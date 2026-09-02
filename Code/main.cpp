#define GLFW_INCLUDE_VULKAN
#include "glm/glm.hpp"
#include "GLFW/glfw3.h"
#include "vulkan/vulkan.h"
#include <iostream>

int main() {
	
	glm::vec3 testVec(1.0f, 2.f, 3.f);
	std::cout << glm::length(testVec) << std::endl;

	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.apiVersion = VK_API_VERSION_1_4;
	appInfo.pApplicationName = "testVulkan";

	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	VkInstance instance;
	VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
	if (result != VK_SUCCESS) {
		std::cerr << "Failed to create Vulkan instance: " << result << std::endl; 
		return -1;
	}

	std::cout << "Vulkan instance created successfully!" << std::endl;
	return 0;
}