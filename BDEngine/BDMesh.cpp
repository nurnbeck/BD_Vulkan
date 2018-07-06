#include "BDMesh.h"
#include <sstream>

namespace BDEngine {

	BDMesh::BDMesh( )
	{
	}


	BDMesh::~BDMesh( )
	{
	}

	bool BDMesh::Load( std::string filename ) noexcept
	{
		std::ifstream myFile{};
		myFile.open( filename );
		if ( myFile.fail( ) ) 
		{ 
			std::cout << "we had a huge failerino" << std::endl;
			return false;
		}
		std::string str = "";
		int size = 0;



		vertices.clear( );
		while ( std::getline( myFile, str ) ) 
		{
			if ( str.empty( ) ) { continue; }
			if ( str.at( 0 ) == 'v' )
			{

				std::stringstream strStream{ str };
				char ignore;
				Vertex v{};
				float z = 0;
				v.color.r = 1;
				v.color.g = 1;
				v.color.b = 1;
				strStream >> ignore >> v.pos.x >> v.pos.y >> v.pos.z;
				v.pos.x += 180;
				v.pos.y -= 100;
				v.pos.y /= 50;
				v.pos.x /= 50;
				v.pos.z /= 50;
				std::cout << " " << v.pos.x << " " << v.pos.y << " " << std::endl;
				vertices.push_back( v );
			}
			else if ( str.at( 0 ) == 'f' )
			{
				std::stringstream strStream{ str };
				int a, b, c;
				char ignore;
				strStream >> ignore >> a >> b >> c;
				indices.push_back( a-1 );
				indices.push_back( b-1 );
				indices.push_back( c - 1 );
			}
			else if ( str.at( 0 ) == 'g' )
			{
				//groups are not supported for now
			}
			else { 
				
			}
		}
		return true;
	}

	void* BDMesh::GetVertexData( )
	{
		return &vertices [ 0 ];
	}
	void* BDMesh::GetIndexData( )
	{
		return &indices [ 0 ];
	}
	size_t BDMesh::GetVertexCount()
	{
		return vertices.size( );
	}
	size_t BDMesh::GetIndexCount( )
	{
		return vertices.size( );
	}
}
