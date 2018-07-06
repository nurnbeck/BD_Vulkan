#pragma once

#include "BDBuffer.h"
namespace BDEngine
{
	class BDVertexBuffer : public BDBuffer
	{
	public:
		BDVertexBuffer(const VkDevice* logicalDevice, const VkPhysicalDevice* physicalDevice, const VkSurfaceKHR* surface,
			const VkCommandPool* transferCommandPool, const VkQueue* transferQueue);
		~BDVertexBuffer();

		void Create(const VkDevice* logicalDevice, const VkPhysicalDevice* physicalDevice, const VkSurfaceKHR* surface,
			const VkCommandPool* transferCommandPool, const VkQueue* transferQueue);
		void Cleanup(const VkDevice* logicalDevice);

		//Getters
		//uint32_t GetVerticesSize() { return vertices.size(); }
	private:

	/*	const std::vector<Vertex> vertices = 
		{
			{ { -0.5f, -0.5f },{ 1.0f, 1.0f, 1.0f } },
			{ {0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}},
			{ { 0.5f, 0.5f },{ 0.0f, 1.0f, 0.0f } },
			{ {-0.5f, 0.5f},{ 0.0f, 0.0f, 1.0f } }
		};*/
	};
}

