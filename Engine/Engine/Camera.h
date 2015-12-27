#pragma once
#include <gtc/matrix_transform.hpp>

#include "glew.h"

class Camera {
public:
	Camera();
	const glm::vec3&		position() const;
	void					setPosition(const glm::vec3& position);
	void					offsetPosition(const glm::vec3& offset);
	float					fieldOfView() const;
	void					setFieldOfView(float fieldOfView);
	float					nearPlane() const;
	float					farPlane() const;
	void					setNearAndFarPlanes(float nearPlane, float farPlane);
	glm::mat4				orientation() const;
	void					offsetOrientation(float upAngle, float rightAngle);
	void					lookAt(glm::vec3 position);
	float					viewportAspectRatio() const;
	void					setViewportAspectRatio(float viewportAspectRatio);

	void Camera::Initialize();

	glm::vec3				forward() const;
	glm::vec3				right() const;
	glm::vec3				up() const;

	glm::mat4				matrix() const;
	glm::mat4				projection() const;
	glm::mat4				view() const;

	void					InputCameraHandler(void);

	GLuint					UBO;

private:
	glm::vec3				_position;
	float					_horizontalAngle;
	float					_verticalAngle;
	float					_fieldOfView;
	float					_nearPlane;
	float					_farPlane;
	float					_viewportAspectRatio;
	float					_cameraSensitivity;
	float					_cameraSpeed;
	float					_depth;

	void					normalizeAngles();
};

