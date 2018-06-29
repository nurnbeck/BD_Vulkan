#pragma once
#include <vulkan/vulkan.h>
#include <iostream>
namespace BDEngine
{
	class BDCommandPool
	{
	public:
		BDCommandPool(const VkDevice* logicalDevice, uint32_t queueFamilyIndex, VkCommandPoolCreateFlags flags = 0);
		~BDCommandPool();

		void Cleanup(const VkDevice* logicalDevice);

		VkCommandPool* GetCommandPool() { return &commandPool; }
	private:
		void createCommandPool(const VkDevice* logicalDevice, uint32_t queueFamilyIndex, VkCommandPoolCreateFlags flags = 0);
		VkCommandPool commandPool;
	};
}

