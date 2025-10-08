# Jenkins Email Templates

This directory contains HTML email templates for Jenkins build notifications.

## Template Files

- **`success.html`** - Template for successful builds
- **`failure.html`** - Template for failed builds  
- **`unstable.html`** - Template for unstable builds (test failures)

## Template Variables

The following variables are automatically replaced when emails are sent:

| Variable | Description |
|----------|-------------|
| `${JOB_NAME}` | Jenkins job/project name |
| `${BUILD_NUMBER}` | Current build number |
| `${BUILD_URL}` | URL to the build in Jenkins |
| `${GIT_COMMIT}` | Git commit hash |
| `${BUILD_DURATION}` | How long the build took |
| `${DOCKER_IMAGE_NAME}` | Docker image name |
| `${DOCKER_TAG}` | Docker image tag |
| `${STAGE_NAME}` | Failed stage name (failure template) |
| `${BUILD_DESCRIPTION}` | Build description/error details |

## Customizing Templates

1. Edit the HTML files in this directory
2. Use standard HTML and CSS for styling
3. Include the template variables where needed
4. The Jenkinsfile will automatically load and process the templates

## File Structure

```
jenkins/
├── email-templates/
│   ├── success.html
│   ├── failure.html
│   ├── unstable.html
│   └── README.md
```

## Usage in Jenkinsfile

Templates are loaded using the `getEmailTemplate()` function:

```groovy
body: getEmailTemplate('success')
```

This system makes email templates easier to maintain and allows for rich HTML formatting without cluttering the Jenkinsfile.