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
            
            stage('Build Dependencies') {
                steps {
                    echo 'Installing build dependencies...'
                    sh '''
                        # Update and install required packages
                        sudo apt-get update
                        sudo apt-get install -y cmake build-essential
                    '''
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
            
            // stage('Build Docker Image') {
            //     steps {
            //         echo 'Building Docker image...'
            //         script {
            //             def dockerImage = docker.build("${DOCKER_IMAGE_NAME}:${DOCKER_TAG}")
            //             env.DOCKER_IMAGE_ID = dockerImage.id
            //         }
            //     }
            // }
            
            // stage('Test Docker Image') {
            //     steps {
            //         echo 'Testing Docker image...'
            //         sh '''
            //             # Run container to test it works
            //             docker run --rm ${DOCKER_IMAGE_NAME}:${DOCKER_TAG} ./calculator_test_harness
            //         '''
            //     }
            // }
            
            // stage('Push to Docker Hub') {
            //     steps {
            //         echo 'Pushing Docker image to Docker Hub...'
            //         script {
            //             docker.withRegistry('https://index.docker.io/v1/', 'dockerhub-credentials') {
            //                 def dockerImage = docker.image("${DOCKER_IMAGE_NAME}:${DOCKER_TAG}")
            //                 dockerImage.push()
            //                 dockerImage.push('latest')
            //             }
            //         }
            //     }
            // }
            
            // stage('Deploy with Ansible') {
            //     steps {
            //         echo 'Deploying application using Ansible...'
            //         sh '''
            //             # Run Ansible playbook for deployment
            //             ansible-playbook -i ansible/inventory ansible/deploy.yml --extra-vars "docker_image=${DOCKER_IMAGE_NAME}:${DOCKER_TAG}"
            //         '''
            //     }
            // }
            
            // stage('Cleanup') {
            //     steps {
            //         echo 'Cleaning up...'
            //         sh '''
            //             # Clean up local Docker images to save space
            //             // docker image prune -f
                        
            //             # Remove build artifacts if needed
            //             # rm -rf build/
            //         '''
            //     }
            // }
        }
        
        post {
            always {
                echo 'Pipeline execution completed'
                // Archive artifacts
                archiveArtifacts artifacts: 'build/calculator_app, build/calculator_test_harness', allowEmptyArchive: true
            }
            success {
                echo 'Pipeline executed successfully!'
                // Send success notification
            }
            failure {
                echo 'Pipeline failed!'
                // Send failure notification
            }
            cleanup {
                // Clean workspace
                cleanWs()
            }
        }
    }