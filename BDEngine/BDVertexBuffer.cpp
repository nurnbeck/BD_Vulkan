#include "BDVertexBuffer.h"
#include "BDMesh.h"

namespace BDEngine
{

	BDVertexBuffer::BDVertexBuffer(const VkDevice* logicalDevice, const VkPhysicalDevice* physicalDevice, const VkSurfaceKHR* surface,
		const VkCommandPool* transferCommandPool, const VkQueue* transferQueue)
	{
		Create(logicalDevice, physicalDevice, surface, transferCommandPool, transferQueue);
	}


	BDVertexBuffer::~BDVertexBuffer()
	{
	}

	void BDVertexBuffer::Create(const VkDevice* logicalDevice, const VkPhysicalDevice* physicalDevice, const VkSurfaceKHR* surface,
		const VkCommandPool* transferCommandPool, const VkQueue* transferQueue)
	{
		//VkDeviceSize bufferSize = sizeof(vertices[0]) * vertices.size();
		BDMesh Teapot;
		Teapot.Load( "D:\\BeamDogVulkan\\BeamDogVulkan\\TesterGame\\Meshes\\utah-teapot.obj" );
		VkDeviceSize bufferSize = sizeof( Vertex ) * Teapot.GetVertexCount();
		VkBuffer stagingBuffer;
		VkDeviceMemory stagingBufferMemory;

		createBuffer(logicalDevice, physicalDevice, surface, bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, 
			VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, stagingBuffer, stagingBufferMemory);

		void* data;
		vkMapMemory(*logicalDevice, stagingBufferMemory, 0, bufferSize, 0, &data);
		//memcpy(data, vertices.data(), (size_t)bufferSize);
		memcpy( data, Teapot.GetVertexData( ), (size_t)bufferSize );
		vkUnmapMemory(*logicalDevice, stagingBufferMemory);

		createBuffer(logicalDevice, physicalDevice, surface, bufferSize, VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
			VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, buffer, bufferMemory);

		copyBuffer(logicalDevice, transferCommandPool, stagingBuffer, buffer, bufferSize, transferQueue);

		vkDestroyBuffer(*logicalDevice, stagingBuffer, nullptr);
		vkFreeMemory(*logicalDevice, stagingBufferMemory, nullptr);
	}

	void BDVertexBuffer::Cleanup(const VkDevice* logicalDevice)
	{
		cleanupBuffer(logicalDevice, buffer, bufferMemory);
	}	
}
