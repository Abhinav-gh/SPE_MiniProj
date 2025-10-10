def getEmailTemplate(templateName) {
    try {
        echo "Loading template: jenkins/email-templates/${templateName}.html"
        def template = readFile("jenkins/email-templates/${templateName}.html")
        echo "Template loaded successfully, length: ${template.length()}"
        
        // Replace only essential variables
        template = template.replace('${JOB_NAME}', env.JOB_NAME)
        template = template.replace('${BUILD_NUMBER}', env.BUILD_NUMBER)
        template = template.replace('${BUILD_URL}', env.BUILD_URL)
        
        echo "Template processing completed"
        return template
    } catch (Exception e) {
        echo "Error loading template: ${e.getMessage()}"
        return "<h2>Build ${templateName.toUpperCase()}</h2><p>Project: ${env.JOB_NAME}</p><p>Build: #${env.BUILD_NUMBER}</p><p><a href='${env.BUILD_URL}'>View Details</a></p>"
    }
}

pipeline {
        agent any
        
        environment {
            DOCKER_HUB_CREDENTIALS = credentials('Abhinav_Docker')
            DOCKER_IMAGE_NAME = 'darklordrises/spe_miniproj'
            DOCKER_TAG = "${BUILD_NUMBER}"
            NOTIFICATION_EMAIL = 'work.abhinav.work@gmail.com'
        }
        
        stages {
            // happens by default so no need
            // stage('Checkout') {
            //     steps {
            //         echo 'Checking out source code...'
            //         checkout scm
            //     }
            // }
            
            stage('Build Application') {
                steps {
                    echo 'Building the scientific calculator application...'
                    sh '''
                        mkdir -p build
                        cd build
                        cmake ..
                        make -j$(nproc)
                        ls -la calculator_app calculator_test_harness
                    '''
                }
            }
            
            stage('Run Tests') {
                steps {
                    echo 'Running unit tests...'
                    sh '''
                        cd build
                        ./calculator_test_harness
                        make run_tests  
                    '''
                }
                post {
                    always {
                        echo 'Test execution completed'
                    }
                    success {
                        echo 'All tests passed successfully!'
                    }
                    failure {
                        echo 'Tests failed!'
                        error 'Test execution failed'
                    }
                }
            }
            
            stage('Build Docker Image') {
                steps {
                    echo 'Building Docker image...'
                    script {
                        def dockerImage = docker.build("${DOCKER_IMAGE_NAME}:${DOCKER_TAG}")
                        env.DOCKER_IMAGE_ID = dockerImage.id
                    }
                }
            }
            
            stage('Push to Docker Hub') {
                steps {
                    echo 'Pushing Docker image to Docker Hub...'
                    script {
                        docker.withRegistry('https://index.docker.io/v1/', 'Abhinav_Docker') {
                            def dockerImage = docker.image("${DOCKER_IMAGE_NAME}:${DOCKER_TAG}")
                            dockerImage.push()
                            dockerImage.push('latest')
                        }
                    }
                }
            }
            
            stage('Deploy with Ansible') {
                steps {
                    echo 'Deploying application using Ansible...'
                    sh '''
                        ansible-playbook -i ansible/inventory ansible/deploy.yml
                    '''
                }
            }
            
        }
        
        post {
            always {
                echo 'Pipeline execution completed'
                // Archive artifacts
                archiveArtifacts artifacts: 'build/calculator_app, build/calculator_test_harness', allowEmptyArchive: true
            }
            success {
                echo 'Pipeline executed successfully!'
                script {
                    try {
                        echo "Sending success email to: ${env.NOTIFICATION_EMAIL}"
                        emailext (
                            subject: "✅ SUCCESS: ${env.JOB_NAME} - Build #${env.BUILD_NUMBER}",
                            body: getEmailTemplate('success'),
                            mimeType: 'text/html',
                            to: "${env.NOTIFICATION_EMAIL}"
                        )
                        echo "Success email sent successfully"
                    } catch (Exception e) {
                        echo "Failed to send success email: ${e.getMessage()}"
                    }
                }
            }
            failure {
                echo 'Pipeline failed!'
                script {
                    try {
                        echo "Sending failure email to: ${env.NOTIFICATION_EMAIL}"
                        emailext (
                            subject: "❌ FAILED: ${env.JOB_NAME} - Build #${env.BUILD_NUMBER}",
                            body: "<h2>Build Failed!</h2><p>Project: ${env.JOB_NAME}</p><p>Build: #${env.BUILD_NUMBER}</p><p><a href='${env.BUILD_URL}'>View Details</a></p>",
                            mimeType: 'text/html',
                            to: "${env.NOTIFICATION_EMAIL}"
                        )
                        echo "Failure email sent successfully"
                    } catch (Exception e) {
                        echo "Failed to send failure email: ${e.getMessage()}"
                    }
                }
            }
            unstable {
                echo 'Pipeline unstable!'
                script {
                    emailext (
                        subject: "⚠️ UNSTABLE: ${env.JOB_NAME} - Build #${env.BUILD_NUMBER}",
                        body: getEmailTemplate('unstable'),
                        mimeType: 'text/html',
                        to: "${env.NOTIFICATION_EMAIL}"
                    )
                }
            }
            cleanup {
                // Clean workspace
                cleanWs() 
            }
        }
    }