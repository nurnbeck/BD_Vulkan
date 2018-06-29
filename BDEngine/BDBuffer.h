#pragma once
#include "BDVertex.h"
#include <iostream>
#include <vector>
namespace BDEngine
{
	class BDBuffer
	{
	public:
		BDBuffer();
		~BDBuffer();

		VkBuffer* GetBuffer() { return &buffer; }

	protected:
		void createBuffer(const VkDevice* logicalDevice, const VkPhysicalDevice* physicalDevice,
			const VkSurfaceKHR* surface, VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, 
			VkBuffer& buffer, VkDeviceMemory& bufferMemory);

		void cleanupBuffer(const VkDevice* logicalDevice, VkBuffer& buffer, VkDeviceMemory& bufferMemory);

		uint32_t findMemoryType(VkPhysicalDevice physicalDevice, uint32_t typeFilter, VkMemoryPropertyFlags properties);

		void copyBuffer(const VkDevice* logicalDevice, const VkCommandPool* commandPool, VkBuffer srcBuffer, 
			VkBuffer dstBuffer, VkDeviceSize size, const VkQueue* queue);

	protected:
		VkBuffer buffer;
		VkDeviceMemory bufferMemory;
	};
}

