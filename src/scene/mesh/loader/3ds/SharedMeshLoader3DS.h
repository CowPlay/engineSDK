/*
 * SharedMeshLoader3DS.h
 *
 *  Created on: Nov 12, 2012
 *      Author: gregorytkach
 */

#ifndef SHAREDMESHLOADER3DS_H_
#define SHAREDMESHLOADER3DS_H_

#include "core/collections/array.h"
#include "core/math/matrix4.h"
#include "SChunkData.h"
#include "SCurrentMaterial.h"
#include "SMaterialGroup.h"
#include "scene/mesh/IMeshBuffer.h"

namespace irrgame
{

	namespace io
	{
		class IReadFile;
	}  // namespace io

	namespace scene
	{

		class IMesh;

		class SharedMeshLoader3DS
		{
			public:
				//! Singleton realization
				static SharedMeshLoader3DS& getInstance();

			private:
				//! Default constructor. Should use only one time.
				SharedMeshLoader3DS();

				//! Destructor. Should use only one time.
				virtual ~SharedMeshLoader3DS();

				//! Copy constructor. Do not implement.
				SharedMeshLoader3DS(const SharedMeshLoader3DS& root);

				//! Override equal operator. Do not implement.
				const SharedMeshLoader3DS& operator=(SharedMeshLoader3DS&);

				/*
				 * Methods
				 */

			public:

				//! creates/loads an animated mesh from the file.
				//! \return Pointer to the created mesh.
				//! If you no longer need the mesh, you should call IAnimatedMesh::drop().
				//! See IReferenceCounted::drop() for more information.
				IMesh* createMesh(io::IReadFile* file);

			private:
				void cleanUp();

				bool readChunk(io::IReadFile* file, SChunkData* parent);
				void readChunkData(io::IReadFile* file, SChunkData& data);
				bool readMaterialChunk(io::IReadFile* file, SChunkData* parent);
				bool readFrameChunk(io::IReadFile* file, SChunkData* parent);
				bool readTrackChunk(io::IReadFile* file, SChunkData& data,
						IMeshBuffer* mb, const vector3df& pivot);
				bool readObjectChunk(io::IReadFile* file, SChunkData* parent);
				bool readPercentageChunk(io::IReadFile* file, SChunkData* chunk,
						f32& percentage);
				bool readColorChunk(io::IReadFile* file, SChunkData* chunk,
						video::SColor& out);
				void readString(io::IReadFile* file, SChunkData& data,
						core::stringc& out);
				void readVertices(io::IReadFile* file, SChunkData& data);
				void readIndices(io::IReadFile* file, SChunkData& data);
				void readMaterialGroup(io::IReadFile* file, SChunkData& data);
				void readTextureCoords(io::IReadFile* file, SChunkData& data);

				void composeObject(io::IReadFile* file,
						const core::stringc& name);
				void loadMaterials(io::IReadFile* file);

			private:
				//				scene::ISceneManager* SceneManager;

				// Pointer to vertices which contains in specify mesh
				f32* Vertices;
				// Vertices count
				u16 VerticesCount;

				// Pointer to indices which contains in specify mesh
				u16* Indices;
				// Count of faces. CountFace = CountIndices / 4
				u16 FacesCount;
				// Temportary array for indices
//				core::array<u16> TempIndices;

				//TODO: comment
				u32* SmoothingGroups;

				// Pointer to texture coordinates which contains in specify mesh
				f32* TCoords;
				// Count of texture coords
				u16 TCoordsCount;

				//TODO:comment
				core::array<SMaterialGroup> MaterialGroups;

				//TODO:comment
				SCurrentMaterial CurrentMaterial;
				//TODO:comment
				core::array<SCurrentMaterial> Materials;

				//TODO: comment
				core::array<core::stringc> MeshBufferNames;

				//TODO: comment
				matrix4f TransformationMatrix;

				//TODO: comment
				IMesh* Mesh;
		};

	} /* namespace scene */
} /* namespace irrgame */
#endif /* SHAREDMESHLOADER3DS_H_ */
