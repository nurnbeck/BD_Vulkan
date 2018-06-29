#include "BDCommandPool.h"

namespace BDEngine
{

	BDCommandPool::BDCommandPool(const VkDevice* logicalDevice, uint32_t queueFamilyIndex, VkCommandPoolCreateFlags flags /* = 0 */)
	{
		createCommandPool(logicalDevice, queueFamilyIndex, flags);
	}


	BDCommandPool::~BDCommandPool()
	{
	}

	void BDCommandPool::Cleanup(const VkDevice* logicalDevice)
	{
		vkDestroyCommandPool(*logicalDevice, commandPool, VK_NULL_HANDLE);
	}

	void BDCommandPool::createCommandPool(const VkDevice* logicalDevice, uint32_t queueFamilyIndex, VkCommandPoolCreateFlags flags /* = 0 */)
	{
		VkCommandPoolCreateInfo poolInfo = {};
		poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
		poolInfo.queueFamilyIndex = queueFamilyIndex;
		poolInfo.flags = flags;

		if (vkCreateCommandPool(*logicalDevice, &poolInfo, nullptr, &commandPool) != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to create command pool");
		}
		else
		{
			std::cout << "Command Pool created successfully" << std::endl;
		}
	}
}
