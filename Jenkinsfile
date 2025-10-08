    pipeline {
        agent any
        
        environment {
            DOCKER_HUB_CREDENTIALS = credentials('Abhinav_Docker')
            DOCKER_IMAGE_NAME = 'darklordrises/spe_miniproj'
            DOCKER_TAG = "${BUILD_NUMBER}"
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
                        
                        # Configure with CMake
                        cmake ..
                        
                        # Build
                        make -j$(nproc)
                        
                        # Verify executables are created
                        ls -la calculator_app calculator_test_harness
                    '''
                }
            }
            
            stage('Run Tests') {
                steps {
                    echo 'Running unit tests...'
                    sh '''
                        cd build
                        
                        # Run the test harness
                        ./calculator_test_harness
                        
                        # Run custom test target
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
            
            stage('Code Quality Check') {
                steps {
                    echo 'Running code quality checks...'
                    sh '''
                        # Check if source files exist and are readable
                        find src/ include/ tests/ -name "*.cpp" -o -name "*.h" | head -10
                        
                        # Basic code metrics
                        echo "Line count in source files:"
                        find src/ include/ tests/ -name "*.cpp" -o -name "*.h" | xargs wc -l
                    '''
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
                        # Run Ansible playbook for deployment
                        ansible-playbook -i ansible/inventory ansible/deploy.yml --extra-vars "docker_image=${DOCKER_IMAGE_NAME}:${DOCKER_TAG}"
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
                    subject: "SUCCESS: ${env.JOB_NAME} - Build #${env.BUILD_NUMBER}",
                    body: """
                    <h2>🎉 Build Successful!</h2>
                    <p><strong>Project:</strong> ${env.JOB_NAME}</p>
                    <p><strong>Build Number:</strong> ${env.BUILD_NUMBER}</p>
                    <p><strong>Build URL:</strong> <a href="${env.BUILD_URL}">${env.BUILD_URL}</a></p>
                    <p><strong>Git Commit:</strong> ${env.GIT_COMMIT}</p>
                    <p><strong>Duration:</strong> ${currentBuild.durationString}</p>
                    
                    <h3>All Stages Completed:</h3>
                    <ul>
                        <li>Code Checkout</li>
                        <li> Application Build</li>
                        <li> Test harness </li>
                        <li> Code Quality Check</li>
                        <li> Docker Image Build</li>
                        <li> Docker Hub Push</li>
                        <li> Ansible Deployment</li>
                    </ul>
                    
                    <p><strong>Docker Image:</strong> ${DOCKER_IMAGE_NAME}:${DOCKER_TAG}</p>
                    <p>🚀 Application deployed successfully!</p>
                    """,
                    mimeType: 'text/html',
                    to: "your-actual-email@gmail.com"
                )
            }
            failure {
                echo 'Pipeline failed!'
                emailext (
                    subject: "❌ FAILED: ${env.JOB_NAME} - Build #${env.BUILD_NUMBER}",
                    body: """
                    <h2>💥 Build Failed!</h2>
                    <p><strong>Project:</strong> ${env.JOB_NAME}</p>
                    <p><strong>Build Number:</strong> ${env.BUILD_NUMBER}</p>
                    <p><strong>Build URL:</strong> <a href="${env.BUILD_URL}">${env.BUILD_URL}</a></p>
                    <p><strong>Console Output:</strong> <a href="${env.BUILD_URL}/console">${env.BUILD_URL}/console</a></p>
                    <p><strong>Git Commit:</strong> ${env.GIT_COMMIT}</p>
                    <p><strong>Duration:</strong> ${currentBuild.durationString}</p>
                    
                    <h3>❌ Failed Stage:</h3>
                    <p><strong>Stage:</strong> ${env.STAGE_NAME}</p>
                    
                    <h3>🔍 Failure Details:</h3>
                    <pre style="background-color: #f5f5f5; padding: 10px; border-radius: 5px;">
                    ${currentBuild.description ?: 'Check console output for detailed error information'}
                    </pre>
                    
                    <p>⚠️ Please check the console output and fix the issues.</p>
                    """,
                    mimeType: 'text/html',
                    to: "your-actual-email@gmail.com"
                )
            }
            unstable {
                echo 'Pipeline unstable!'
                emailext (
                    subject: "⚠️ UNSTABLE: ${env.JOB_NAME} - Build #${env.BUILD_NUMBER}",
                    body: """
                    <h2>⚠️ Build Unstable!</h2>
                    <p><strong>Project:</strong> ${env.JOB_NAME}</p>
                    <p><strong>Build Number:</strong> ${env.BUILD_NUMBER}</p>
                    <p><strong>Build URL:</strong> <a href="${env.BUILD_URL}">${env.BUILD_URL}</a></p>
                    <p><strong>Test Results:</strong> <a href="${env.BUILD_URL}/testReport">${env.BUILD_URL}/testReport</a></p>
                    
                    <p>🧪 Some tests may have failed or warnings were generated.</p>
                    <p>Please review the test results and console output.</p>
                    """,
                    mimeType: 'text/html',
                    to: "your-actual-email@gmail.com"
                )
            }
            cleanup {
                // Clean workspace
                cleanWs()
            }
        }
    }