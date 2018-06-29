#pragma once

#include "BDBuffer.h"

#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>

#include <chrono>

namespace BDEngine
{
	class BDUniformBuffer : public BDBuffer
	{
	public:

		struct UniformBufferObject
		{
			glm::mat4 model;
			glm::mat4 view;
			glm::mat4 proj;
		};


		BDUniformBuffer(const VkDevice* logicalDevice, const VkPhysicalDevice* physicalDevice, const VkSurfaceKHR* surface,
			const VkCommandPool* transferCommandPool, const VkQueue* transferQueue);
		~BDUniformBuffer();

		void CreateUniformBuffer(const VkDevice* logicalDevice, const VkPhysicalDevice* physicalDevice, const VkSurfaceKHR* surface,
			const VkCommandPool* transferCommandPool, const VkQueue* transferQueue);
		void CleanupUniformBuffer(const VkDevice* logicalDevice);

		void Update(const VkDevice* logicalDevice, const VkExtent2D &swapChainExtent);

		//Getters
		VkDeviceSize GetUniformBufferSize() { return sizeof(UniformBufferObject); }

	private:

	
	};
}

