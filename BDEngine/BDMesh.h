#pragma once
#include "BDVertex.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

namespace BDEngine {
	class BDMesh
	{
	public:
		BDMesh( );
		~BDMesh( );

		bool Load( std::string file ) noexcept;

		void * GetVertexData( );
		size_t GetVertexCount( );

		void * GetIndexData( );
		size_t GetIndexCount( );

	private:
		std::vector<Vertex> vertices{};
		std::vector<uint32_t> indices{};
	};
}
