def getEmailTemplate(templateName) {
    def template = readFile("jenkins/email-templates/${templateName}.html")
    
    // Replace only essential variables
    template = template.replace('${JOB_NAME}', env.JOB_NAME)
    template = template.replace('${BUILD_NUMBER}', env.BUILD_NUMBER)
    template = template.replace('${BUILD_URL}', env.BUILD_URL)
    
    return template
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
            stage('Checkout') {
                steps {
                    echo 'Checking out source code...'
                    checkout scm
                }
            }
            
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
                emailext (
                    subject: "✅ SUCCESS: ${env.JOB_NAME} - Build #${env.BUILD_NUMBER}",
                    body: getEmailTemplate('success'),
                    mimeType: 'text/html',
                    to: "${env.NOTIFICATION_EMAIL}"
                )
            }
            failure {
                echo 'Pipeline failed!'
                emailext (
                    subject: "❌ FAILED: ${env.JOB_NAME} - Build #${env.BUILD_NUMBER}",
                    body: getEmailTemplate('failure'),
                    mimeType: 'text/html',
                    to: "${env.NOTIFICATION_EMAIL}"
                )
            }
            unstable {
                echo 'Pipeline unstable!'
                emailext (
                    subject: "⚠️ UNSTABLE: ${env.JOB_NAME} - Build #${env.BUILD_NUMBER}",
                    body: getEmailTemplate('unstable'),
                    mimeType: 'text/html',
                    to: "${env.NOTIFICATION_EMAIL}"
                )
            }
            cleanup {
                // Clean workspace
                cleanWs() 
            }
        }
    }