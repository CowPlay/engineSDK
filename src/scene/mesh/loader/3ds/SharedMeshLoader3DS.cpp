///*
// * SharedMeshLoader3DS.cpp
// *
// *  Created on: Nov 12, 2012
// *      Author: gregorytkach
// */
//
//#include "SharedMeshLoader3DS.h"
//#include "E3DSChunk.h"
//#include "scene/mesh/IMesh.h"
//#include "core/math/SharedMath.h"
//#include "video/vertex.h"
//#include "io/IReadFile.h"
//
//namespace irrgame
//{
//	namespace scene
//	{
//		//! Singleton realization
//		SharedMeshLoader3DS& SharedMeshLoader3DS::getInstance()
//		{
//			static SharedMeshLoader3DS instance;
//			return instance;
//		}
//
//		//! Default constructor. Should use only one time.
//		SharedMeshLoader3DS::SharedMeshLoader3DS()
//		{
//		}
//
//		//! Destructor. Should use only one time.
//		SharedMeshLoader3DS::~SharedMeshLoader3DS()
//		{
//			cleanUp();
//		}
//
//		/*
//		 * Methods
//		 */
//
//		//! creates/loads an animated mesh from the file.
//		IMesh* SharedMeshLoader3DS::createMesh(io::IReadFile* file)
//		{
//			IRR_ASSERT(file)
//
//			SChunkData data;
//
//			readChunkData(file, data);
//
//			if (data.Header.ID != C3DS_MAIN3DS)
//			{
//				//file isn't 3ds
//				IRR_ASSERT(false);
//			}
//
//			CurrentMaterial.clear();
//			Materials.clear();
//			MeshBufferNames.clear();
//			cleanUp();
//			//
//			//			if (Mesh)
//			//			Mesh->drop();
//			//
//			//			Mesh = new SMesh();
//			//
//			//			if (readChunk(file, &data))
//			//			{
//			//				// success
//			//
//			//				for (u32 i=0; i<Mesh->getMeshBufferCount(); ++i)
//			//				{
//			//					SMeshBuffer* mb = ((SMeshBuffer*)Mesh->getMeshBuffer(i));
//			//					// drop empty buffers
//			//					if (mb->getIndexCount() == 0 || mb->getVertexCount() == 0)
//			//					{
//			//						Mesh->MeshBuffers.erase(i--);
//			//						mb->drop();
//			//					}
//			//					else
//			//					{
//			//						if (mb->Material.MaterialType == video::EMT_PARALLAX_MAP_SOLID)
//			//						{
//			//							SMesh tmp;
//			//							tmp.addMeshBuffer(mb);
//			//							mb->drop();
//			//							IMesh* tangentMesh = SceneManager->getMeshManipulator()->createMeshWithTangents(&tmp);
//			//							Mesh->MeshBuffers[i]=tangentMesh->getMeshBuffer(0);
//			//							// we need to grab because we replace the buffer manually.
//			//							Mesh->MeshBuffers[i]->grab();
//			//							// clean up intermediate mesh struct
//			//							tangentMesh->drop();
//			//						}
//			//						Mesh->MeshBuffers[i]->recalculateBoundingBox();
//			//					}
//			//				}
//			//
//			//				Mesh->recalculateBoundingBox();
//			//
//			//				SAnimatedMesh* am = new SAnimatedMesh();
//			//				am->Type = EAMT_3DS;
//			//				am->addMesh(Mesh);
//			//				am->recalculateBoundingBox();
//			//				Mesh->drop();
//			//				Mesh = 0;
//			//				return am;
//			//			}
//			//
//			//			Mesh->drop();
//			//			Mesh = 0;
//			//
//			//			return 0;
//		}
//
//		void SharedMeshLoader3DS::cleanUp()
//		{
//			delete[] Vertices;
//			VerticesCount = 0;
//			Vertices = 0;
//			delete[] Indices;
//			Indices = 0;
//			FacesCount = 0;
//			delete[] SmoothingGroups;
//			SmoothingGroups = 0;
//			delete[] TCoords;
//			TCoords = 0;
//			TCoordsCount = 0;
//
//			MaterialGroups.clear();
//		}
//
//		bool SharedMeshLoader3DS::readChunk(io::IReadFile* file,
//				SChunkData* parent)
//		{
//			IRR_ASSERT(file && parent);
//
//			while (parent->Read < parent->Header.Length)
//			{
//				SChunkData data;
//				readChunkData(file, data);
//
//				switch (data.Header.ID)
//				{
//					case C3DS_VERSION:
//					{
//						u16 version;
//
//						file->read(&version, sizeof(u16));
//						file->seek(data.Header.Length - data.Read - 2, true);
//
//						data.Read += data.Header.Length - data.Read;
//
//						if (version != 0x03)
//						{
//							//3ds file version is other than 3.
//							IRR_ASSERT(false);
//						}
//
//						break;
//					}
//
//					case C3DS_EDIT_MATERIAL:
//					{
//						readMaterialChunk(file, &data);
//						break;
//					}
//					case C3DS_KEYF3DS:
//					{
//						readFrameChunk(file, &data);
//						break;
//					}
//					case C3DS_EDIT3DS:
//					{
//						break;
//					}
//					case C3DS_MESHVERSION:
//					case 0x01:
//					{
//						u32 version;
//						file->read(&version, sizeof(u32));
//						data.Read += sizeof(u32);
//
//						break;
//					}
//
//					case C3DS_EDIT_OBJECT:
//					{
//						core::stringc name;
//						readString(file, data, name);
//						readObjectChunk(file, &data);
//						composeObject(file, name);
//
//						break;
//					}
//
//					default:
//					{
//						// ignore chunk
//						file->seek(data.Header.Length - data.Read, true);
//						data.Read += data.Header.Length - data.Read;
//						break;
//					}
//				}
//
//				parent->Read += data.Read;
//			}
//
//			return true;
//		}
//
//		void SharedMeshLoader3DS::readChunkData(io::IReadFile* file,
//				SChunkData& data)
//		{
//			IRR_ASSERT(file);
//
//			file->read(&data.Header, sizeof(SChunkHeader));
//
//			data.Read += sizeof(SChunkHeader);
//		}
//
//		bool SharedMeshLoader3DS::readMaterialChunk(io::IReadFile* file,
//				SChunkData* parent)
//		{
//			IRR_ASSERT(file && parent);
//
//			//Load material chunk.");
//			u16 matSection = 0;
//
//			while (parent->Read < parent->Header.Length)
//			{
//				SChunkData data;
//				readChunkData(file, data);
//
//				switch (data.Header.ID)
//				{
//					case C3DS_MATNAME:
//					{
//						c8* c = new c8[data.Header.Length - data.Read];
//						file->read(c, data.Header.Length - data.Read);
//
//						if (strlen(c))
//							CurrentMaterial.Name = c;
//
//						data.Read += data.Header.Length - data.Read;
//						delete[] c;
//
//						break;
//					}
//
//					case C3DS_MATAMBIENT:
//					{
//						readColorChunk(file, &data,
//								CurrentMaterial.Material.AmbientColor);
//						break;
//					}
//					case C3DS_MATDIFFUSE:
//					{
//						readColorChunk(file, &data,
//								CurrentMaterial.Material.DiffuseColor);
//						break;
//					}
//						{
//							case C3DS_MATSPECULAR:
//							readColorChunk(file, &data,
//									CurrentMaterial.Material.SpecularColor);
//							break;
//						}
//					case C3DS_MATSHININESS:
//					{
//						readPercentageChunk(file, &data,
//								CurrentMaterial.Material.Shininess);
//						CurrentMaterial.Material.Shininess = (1.f
//								- CurrentMaterial.Material.Shininess) * 128.f;
//						break;
//					}
//					case C3DS_TRANSPARENCY:
//					{
//						f32 percentage;
//						readPercentageChunk(file, &data, percentage);
//
//						if (percentage > 0.0f)
//						{
//							CurrentMaterial.Material.MaterialTypeParam =
//									percentage;
//							CurrentMaterial.Material.MaterialType =
//									video::EMT_TRANSPARENT_VERTEX_ALPHA;
//						}
//						else
//						{
//							CurrentMaterial.Material.MaterialType =
//									video::EMT_SOLID;
//						}
//
//						break;
//					}
//
//					case C3DS_WIRE:
//					{
//						CurrentMaterial.Material.Wireframe = true;
//						break;
//					}
//					case C3DS_TWO_SIDE:
//					{
//						CurrentMaterial.Material.BackfaceCulling = false;
//						break;
//					}
//					case C3DS_SHADING:
//					{
//						s16 flags;
//						file->read(&flags, 2);
//
//						switch (flags)
//						{
//							case 0:
//								CurrentMaterial.Material.Wireframe = true;
//								break;
//							case 1:
//								CurrentMaterial.Material.Wireframe = false;
//								CurrentMaterial.Material.GouraudShading = false;
//								break;
//							case 2:
//								CurrentMaterial.Material.Wireframe = false;
//								CurrentMaterial.Material.GouraudShading = true;
//								break;
//							default:
//								// phong and metal missing
//								break;
//						}
//
//						data.Read += data.Header.Length - data.Read;
//
//						break;
//					}
//
//					case C3DS_MATTEXMAP:
//					case C3DS_MATSPECMAP:
//					case C3DS_MATOPACMAP:
//					case C3DS_MATREFLMAP:
//					case C3DS_MATBUMPMAP:
//					{
//						matSection = data.Header.ID;
//						// Should contain a percentage chunk, but does
//						// not always have it
//						s16 testval;
//						const long pos = file->getPos();
//						file->read(&testval, 2);
//						file->seek(pos, false);
//						if ((testval == C3DS_PERCENTAGE_I)
//								|| (testval == C3DS_PERCENTAGE_F))
//							switch (matSection)
//							{
//								case C3DS_MATTEXMAP:
//									readPercentageChunk(file, &data,
//											CurrentMaterial.Strength[0]);
//									break;
//								case C3DS_MATSPECMAP:
//									readPercentageChunk(file, &data,
//											CurrentMaterial.Strength[1]);
//									break;
//								case C3DS_MATOPACMAP:
//									readPercentageChunk(file, &data,
//											CurrentMaterial.Strength[2]);
//									break;
//								case C3DS_MATBUMPMAP:
//									readPercentageChunk(file, &data,
//											CurrentMaterial.Strength[4]);
//									break;
//
//								default:
//								{
//									//Not implemented
//									IRR_ASSERT(false);
//								}
//							}
//
//						break;
//					}
//
//					case C3DS_MATMAPFILE:
//					{
//						// read texture file name
//						c8* c = new c8[data.Header.Length - data.Read];
//						file->read(c, data.Header.Length - data.Read);
//
//						switch (matSection)
//						{
//							case C3DS_MATTEXMAP:
//							{
//								CurrentMaterial.Filename[0] = c;
//								break;
//							}
//							case C3DS_MATSPECMAP:
//							{
//								CurrentMaterial.Filename[1] = c;
//								break;
//							}
//							case C3DS_MATOPACMAP:
//							{
//								CurrentMaterial.Filename[2] = c;
//								break;
//							}
//							case C3DS_MATREFLMAP:
//							{
//								CurrentMaterial.Filename[3] = c;
//								break;
//							}
//							case C3DS_MATBUMPMAP:
//							{
//								CurrentMaterial.Filename[4] = c;
//								break;
//							}
//							default:
//							{
//								IRR_ASSERT(false);
//								break;
//							}
//						}
//
//						data.Read += data.Header.Length - data.Read;
//						delete[] c;
//
//						break;
//					}
//
//					case C3DS_MAT_TEXTILING:
//					{
//						s16 flags;
//						file->read(&flags, 2);
//						data.Read += 2;
//
//						break;
//					}
//
//					case C3DS_MAT_USCALE:
//					case C3DS_MAT_VSCALE:
//					case C3DS_MAT_UOFFSET:
//					case C3DS_MAT_VOFFSET:
//					{
//						f32 value;
//
//						file->read(&value, 4);
//
//						u32 i = 0;
//
//						if (matSection != C3DS_MATTEXMAP)
//						{
//							i = 1;
//						}
//
//						u32 j = 0;
//						u32 k = 0;
//
//						if (data.Header.ID == C3DS_MAT_VSCALE)
//						{
//							j = 1;
//							k = 1;
//						}
//						else if (data.Header.ID == C3DS_MAT_UOFFSET)
//						{
//							j = 2;
//							k = 0;
//						}
//						else if (data.Header.ID == C3DS_MAT_VOFFSET)
//						{
//							j = 2;
//							k = 1;
//						}
//
//						CurrentMaterial.Material.getTextureMatrix(i)(j, k) =
//								value;
//
//						data.Read += 4;
//
//						break;
//					}
//
//					default:
//					{
//						// ignore chunk
//						file->seek(data.Header.Length - data.Read, true);
//						data.Read += data.Header.Length - data.Read;
//
//						break;
//					}
//				}
//
//				parent->Read += data.Read;
//			}
//
//			Materials.pushBack(CurrentMaterial);
//			CurrentMaterial.clear();
//
//			return true;
//		}
//
//		bool SharedMeshLoader3DS::readFrameChunk(io::IReadFile* file,
//				SChunkData* parent)
//		{
//			IRR_ASSERT(file && parent);
//
//			bool result = false;
//
//			SChunkData data;
//
//			//KF_HDR is always at the beginning
//			readChunkData(file, data);
//
//			if (data.Header.ID != C3DS_KF_HDR)
//				return result;
//
//			result = true;
//
//			//Load keyframe header.
//			u16 version;
//			file->read(&version, 2);
//
//			core::stringc name;
//			readString(file, data, name);
//			u32 flags;
//			file->read(&flags, 4);
//
//			data.Read += 4;
//			parent->Read += data.Read;
//
//			data.Read = 0;
//
//			IMeshBuffer* mb = 0;
//			vector3df pivot, bboxCenter;
//			while (parent->Read < parent->Header.Length)
//			{
//				readChunkData(file, data);
//
//				switch (data.Header.ID)
//				{
//					case C3DS_OBJECT_TAG: 	//Load object tag.
//					{
//						mb = 0;
//						pivot.set(0.0f, 0.0f, 0.0f);
//
//						break;
//					}
//
//					case C3DS_KF_SEG:	//Load keyframe segment.
//					{
//						u32 flags;
//						file->read(&flags, 4);
//						file->read(&flags, 4);
//
//						data.Read += 8;
//
//						break;
//					}
//					case C3DS_KF_NODE_HDR:	 //Load keyframe node header.
//					{
//						s16 flags;
//						c8* c = new c8[data.Header.Length - data.Read - 6];
//						file->read(c, data.Header.Length - data.Read - 6);
//
//						// search mesh buffer to apply these transformations to
//						for (u32 i = 0; i < MeshBufferNames.size(); ++i)
//						{
//							if (MeshBufferNames[i] == c)
//							{
//								mb = Mesh->getMeshBuffer(i);
//								break;
//							}
//						}
//
//						file->read(&flags, 2);
//						file->read(&flags, 2);
//						file->read(&flags, 2);
//
//						data.Read += data.Header.Length - data.Read;
//						delete[] c;
//
//						break;
//					}
//					case C3DS_KF_CURTIME:	//Load keyframe current time.
//					{
//
//						u32 flags;
//						file->read(&flags, 4);
//
//						data.Read += 4;
//
//						break;
//					}
//
//					case C3DS_NODE_ID:	//Load node ID.
//					{
//						u16 flags;
//						file->read(&flags, 2);
//
//						data.Read += 2;
//
//						break;
//					}
//
//					case C3DS_PIVOTPOINT:	//Load pivot point.
//					{
//						file->read(&pivot.X, sizeof(f32));
//						file->read(&pivot.Y, sizeof(f32));
//						file->read(&pivot.Z, sizeof(f32));
//
//						data.Read += 12;
//
//						break;
//					}
//
//					case C3DS_BOUNDBOX: //Load bounding box.
//					{
//						aabbox3df bbox;
//						// abuse bboxCenter as temporary variable
//						file->read(&bboxCenter.X, sizeof(f32));
//						file->read(&bboxCenter.Y, sizeof(f32));
//						file->read(&bboxCenter.Z, sizeof(f32));
//
//						bbox.reset(bboxCenter);
//						file->read(&bboxCenter.X, sizeof(f32));
//						file->read(&bboxCenter.Y, sizeof(f32));
//						file->read(&bboxCenter.Z, sizeof(f32));
//
//						bbox.addInternalPoint(bboxCenter);
//						bboxCenter = bbox.getCenter();
//						data.Read += 24;
//
//						break;
//					}
//
//					case C3DS_MORPH_SMOOTH: //Load morph smooth.
//					{
//						f32 flag;
//						file->read(&flag, 4);
//						data.Read += 4;
//
//						break;
//					}
//
//					case C3DS_POS_TRACK_TAG:
//					case C3DS_ROT_TRACK_TAG:
//					case C3DS_SCL_TRACK_TAG:
//					{
//						readTrackChunk(file, data, mb, bboxCenter - pivot);
//						break;
//					}
//					default:
//					{	// ignore chunk
//						file->seek(data.Header.Length - data.Read, true);
//						data.Read += data.Header.Length - data.Read;
//
//						break;
//					}
//				}
//
//				parent->Read += data.Read;
//				data.Read = 0;
//			}
//
//			return true;
//		}
//
//		bool SharedMeshLoader3DS::readTrackChunk(io::IReadFile* file,
//				SChunkData& data, IMeshBuffer* mb, const vector3df& pivot)
//		{
//			IRR_ASSERT(file && mb);
//
//			//Load track chunk.
//			u16 flags;
//			u32 flags2;
//			// Track flags
//			file->read(&flags, 2);
//			file->read(&flags2, 4);
//			file->read(&flags2, 4);
//			// Num keys
//			file->read(&flags2, 4);
//			file->read(&flags2, 4);
//			// TCB flags
//			file->read(&flags, 2);
//			data.Read += 20;
//
//			f32 angle = 0.0f;
//			if (data.Header.ID == C3DS_ROT_TRACK_TAG)
//			{
//				// Angle
//				file->read(&angle, sizeof(f32));
//				data.Read += sizeof(f32);
//			}
//
//			vector3df vec;
//			file->read(&vec.X, sizeof(f32));
//			file->read(&vec.Y, sizeof(f32));
//			file->read(&vec.Z, sizeof(f32));
//
//			data.Read += 12;
//			vec -= pivot;
//
//			// apply transformation to mesh buffer
//			if (false)	//mb)
//			{
//				video::vertex3d *vertices =
//						(video::vertex3d*) mb->getVertices();
//				if (data.Header.ID == C3DS_POS_TRACK_TAG)
//				{
//					for (u32 i = 0; i < mb->getVertexCount(); ++i)
//						vertices[i].Pos += vec;
//				}
//				else if (data.Header.ID == C3DS_ROT_TRACK_TAG)
//				{
//					//TODO
//				}
//				else if (data.Header.ID == C3DS_SCL_TRACK_TAG)
//				{
//					//TODO
//				}
//			}
//			// skip further frames
//			file->seek(data.Header.Length - data.Read, true);
//			data.Read += data.Header.Length - data.Read;
//
//			return true;
//		}
//
//		bool SharedMeshLoader3DS::readObjectChunk(io::IReadFile* file,
//				SChunkData* parent)
//		{
//			IRR_ASSERT(file && parent);
//			//Load object chunk.
//
//			while (parent->Read < parent->Header.Length)
//			{
//				SChunkData data;
//				readChunkData(file, data);
//
//				switch (data.Header.ID)
//				{
//					case C3DS_OBJTRIMESH:
//						readObjectChunk(file, &data);
//						break;
//
//					case C3DS_TRIVERT:
//						readVertices(file, data);
//						break;
//
//					case C3DS_POINTFLAGARRAY:
//					{
//						u16 numVertex, flags;
//						file->read(&numVertex, sizeof(u16));
//#ifdef __BIG_ENDIAN__
//						numVertex= os::Byteswap::byteswap(numVertex);
//#endif
//						for (u16 i = 0; i < numVertex; ++i)
//						{
//							file->read(&flags, sizeof(u16));
//#ifdef __BIG_ENDIAN__
//							flags = os::Byteswap::byteswap(flags);
//#endif
//						}
//						data.Read += (numVertex + 1) * sizeof(u16);
//					}
//						break;
//
//					case C3DS_TRIFACE:
//					{
//						readIndices(file, data);
//						readObjectChunk(file, &data); // read smooth and material groups
//						break;
//					}
//					case C3DS_TRIFACEMAT:
//					{
//						readMaterialGroup(file, data);
//						break;
//					}
//					case C3DS_TRIUV: // getting texture coordinates
//						readTextureCoords(file, data);
//						break;
//
//					case C3DS_TRIMATRIX:
//					{
//						f32 mat[4][3];
//						file->read(&mat, 12 * sizeof(f32));
//						TransformationMatrix.makeIdentity();
//						for (int i = 0; i < 4; ++i)
//						{
//							for (int j = 0; j < 3; ++j)
//							{
//								TransformationMatrix(i, j) = mat[i][j];
//							}
//						}
//						data.Read += 12 * sizeof(f32);
//
//						break;
//					}
//					case C3DS_MESHCOLOR:
//					{
//						u8 flag;
//						file->read(&flag, sizeof(u8));
//						++data.Read;
//
//						break;
//					}
//					case C3DS_TRISMOOTH: // TODO
//					{
//						SmoothingGroups = new u32[FacesCount];
//						file->read(SmoothingGroups, FacesCount * sizeof(u32));
//						data.Read += FacesCount * sizeof(u32);
//
//						break;
//					}
//					default:
//					{
//						// ignore chunk
//						file->seek(data.Header.Length - data.Read, true);
//						data.Read += data.Header.Length - data.Read;
//
//						break;
//					}
//				}
//
//				parent->Read += data.Read;
//			}
//
//			return true;
//		}
//
//		bool SharedMeshLoader3DS::readPercentageChunk(io::IReadFile* file,
//				SChunkData* chunk, f32& percentage)
//		{
//			//Load percentage chunk.
//
//			SChunkData data;
//			readChunkData(file, data);
//
//			short intpercentage;
//			f32 fpercentage;
//
//			switch (data.Header.ID)
//			{
//				case C3DS_PERCENTAGE_I:
//				{
//					// read short
//					file->read(&intpercentage, 2);
//
//					percentage = intpercentage / 100.0f;
//					data.Read += 2;
//
//					break;
//				}
//				case C3DS_PERCENTAGE_F:
//				{
//					// read float
//					file->read(&fpercentage, sizeof(float));
//					data.Read += sizeof(float);
//					percentage = (f32) fpercentage;
//					break;
//				}
//				default:
//				{
//					//Unknown percentage chunk in 3Ds file.
//
//					//Not implemented
//					IRR_ASSERT(false);
//
//					file->seek(data.Header.Length - data.Read, true);
//					data.Read += data.Header.Length - data.Read;
//
//					break;
//				}
//			}
//
//			chunk->Read += data.Read;
//
//			return true;
//		}
//
//		bool SharedMeshLoader3DS::readColorChunk(io::IReadFile* file,
//				SChunkData* chunk, video::SColor& out)
//		{
//			//Load color chunk.
//
//			IRR_ASSERT(file && chunk);
//
//			SChunkData data;
//			readChunkData(file, data);
//
//			u8 c[3];
//			f32 cf[3];
//
//			switch (data.Header.ID)
//			{
//				case C3DS_COL_TRU:
//				case C3DS_COL_LIN_24:
//				{
//					// read 8 bit data
//					file->read(c, sizeof(c));
//					out.set(255, c[0], c[1], c[2]);
//					data.Read += sizeof(c);
//				}
//					break;
//				case C3DS_COL_RGB:
//				case C3DS_COL_LIN_F:
//				{
//					// read float data
//					file->read(cf, sizeof(cf));
//					out.set(255, (s32) (cf[0] * 255.0f), (s32) (cf[1] * 255.0f),
//							(s32) (cf[2] * 255.0f));
//					data.Read += sizeof(cf);
//
//					break;
//				}
//
//				default:
//				{
//					//Unknown size of color chunk in 3Ds file.
//					IRR_ASSERT(false);
//
//					break;
//				}
//			}
//
//			chunk->Read += data.Read;
//
//			return true;
//		}
//
//		void SharedMeshLoader3DS::readString(io::IReadFile* file,
//				SChunkData& data, core::stringc& out)
//		{
//			IRR_ASSERT(file);
//			c8 c = 1;
//			out = "";
//
//			while (c)
//			{
//				file->read(&c, sizeof(c8));
//				if (c)
//				{
//					out.append(c);
//				}
//			}
//
//			data.Read += out.size() + 1;
//		}
//
//		void SharedMeshLoader3DS::readVertices(io::IReadFile* file,
//				SChunkData& data)
//		{
//			//Load vertices.
//
//			file->read(&VerticesCount, sizeof(VerticesCount));
//
//			data.Read += sizeof(VerticesCount);
//
//			const s32 vertexBufferByteSize = VerticesCount * sizeof(f32) * 3;
//
//			if (data.Header.Length - data.Read != vertexBufferByteSize)
//			{
//				//Invalid size of vertices found in 3ds file
//				IRR_ASSERT(false);
//			}
//
//			Vertices = new f32[VerticesCount * 3];
//			file->read(Vertices, vertexBufferByteSize);
//
//			data.Read += vertexBufferByteSize;
//		}
//
//		void SharedMeshLoader3DS::readIndices(io::IReadFile* file,
//				SChunkData& data)
//		{
//			//Load indices.
//
//			file->read(&FacesCount, sizeof(FacesCount));
//
//			data.Read += sizeof(FacesCount);
//
//			s32 indexBufferByteSize = FacesCount * sizeof(u16) * 4;
//
//			// Indices are u16s.
//			// After every 3 Indices in the array, there follows an edge flag.
//			Indices = new u16[FacesCount * 4];
//			file->read(Indices, indexBufferByteSize);
//
//			data.Read += indexBufferByteSize;
//		}
//
//		void SharedMeshLoader3DS::readMaterialGroup(io::IReadFile* file,
//				SChunkData& data)
//		{
//			//Load material group.
//			IRR_ASSERT(file);
//
//			SMaterialGroup group;
//
//			readString(file, data, group.MaterialName);
//
//			file->read(&group.FaceCount, sizeof(group.FaceCount));
//			data.Read += sizeof(group.FaceCount);
//
//			// read faces
//			group.Faces = new u16[group.FaceCount];
//			file->read(group.Faces, sizeof(u16) * group.FaceCount);
//
//			data.Read += sizeof(u16) * group.FaceCount;
//
//			MaterialGroups.pushBack(group);
//		}
//
//		void SharedMeshLoader3DS::readTextureCoords(io::IReadFile* file,
//				SChunkData& data)
//		{
//			IRR_ASSERT(file);
//			//Load texture coords.
//			file->read(&TCoordsCount, sizeof(TCoordsCount));
//
//			data.Read += sizeof(TCoordsCount);
//
//			s32 tcoordsBufferByteSize = TCoordsCount * sizeof(f32) * 2;
//
//			if (data.Header.Length - data.Read != tcoordsBufferByteSize)
//			{
//				//Invalid size of tcoords found in 3ds file.
//				IRR_ASSERT(false);
//			}
//
//			TCoords = new f32[TCoordsCount * 3];
//			file->read(TCoords, tcoordsBufferByteSize);
//
//			data.Read += tcoordsBufferByteSize;
//		}
//
//		void SharedMeshLoader3DS::composeObject(io::IReadFile* file,
//				const core::stringc& name)
//		{
//			IRR_ASSERT(file);
//
//			if (Mesh->getMeshBufferCount() != Materials.size())
//			{
//				loadMaterials(file);
//			}
//
//			if (MaterialGroups.empty())
//			{
//				// no material group, so add all
//				SMaterialGroup group;
//				group.FaceCount = FacesCount;
//				group.Faces = new u16[group.FaceCount];
//				for (u32 i = 0; i < group.FaceCount; ++i)
//					group.Faces[i] = i;
//				MaterialGroups.pushBack(group);
//
//				// if we've got no material, add one without a texture
//				if (Materials.empty())
//				{
//					SCurrentMaterial m;
//					Materials.pushBack(m);
//					IMeshBuffer* mb = createMeshBuffer();
//					Mesh->addMeshBuffer(mb);
//					mb->getMaterial() = Materials[0].Material;
//					mb->drop();
//					// add an empty mesh buffer name
//					MeshBufferNames.pushBack("");
//				}
//			}
//
//			for (u32 i = 0; i < MaterialGroups.size(); ++i)
//			{
//				IMeshBuffer* mb = 0;
//				video::SMaterial* mat = 0;
//				u32 mbPos;
//				// -3 because we add three vertices at once
//				u32 maxPrimitives =
//						core::StaticMath::min(
//								SceneManager->getVideoDriver()->getMaximalPrimitiveCount(),
//								(u32) ((1 << 16) - 1)) - 3;	// currently hardcoded s16 max value for index pointers
//
//				// find mesh buffer for this group
//				for (mbPos = 0; mbPos < Materials.size(); ++mbPos)
//				{
//					if (MaterialGroups[i].MaterialName == Materials[mbPos].Name)
//					{
//						mb = Mesh->getMeshBuffer(mbPos);
//						mat = &Materials[mbPos].Material;
//						MeshBufferNames[mbPos] = name;
//						break;
//					}
//				}
//
//				if (mb != 0)
//				{
//					// add geometry to the buffer.
//
//					video::S3DVertex vtx;
//					core::vector3df vec;
//					vtx.Color = mat->DiffuseColor;
//					if (mat->MaterialType
//							== video::EMT_TRANSPARENT_VERTEX_ALPHA)
//					{
//						vtx.Color.setAlpha(
//								(int) (255.0f * mat->MaterialTypeParam));
//					}
//					vtx.Normal.set(0, 0, 0);
//
//					for (s32 f = 0; f < MaterialGroups[i].FaceCount; ++f)
//					{
//						u32 vtxCount = mb->Vertices.size();
//						if (vtxCount > maxPrimitives)
//						{
//							IMeshBuffer* tmp = mb;
//							mb = new SMeshBuffer();
//							Mesh->addMeshBuffer(mb);
//							mb->drop();
//							Mesh->MeshBuffers[mbPos] =
//									Mesh->MeshBuffers.getLast();
//							Mesh->MeshBuffers[Mesh->MeshBuffers.size() - 1] =
//									tmp;
//							mb->getMaterial() = tmp->getMaterial();
//							vtxCount = 0;
//						}
//
//						for (s32 v = 0; v < 3; ++v)
//						{
//							s32 idx =
//									Indices[MaterialGroups[i].faces[f] * 4 + v];
//
//							if (CountVertices > idx)
//							{
//								vtx.Pos.X = Vertices[idx * 3 + 0];
//								vtx.Pos.Z = Vertices[idx * 3 + 1];
//								vtx.Pos.Y = Vertices[idx * 3 + 2];
//								//						TransformationMatrix.transformVect(vtx.Pos);
//							}
//
//							if (TCoordsCount > idx)
//							{
//								vtx.TCoords.X = TCoords[idx * 2 + 0];
//								vtx.TCoords.Y = 1.0f - TCoords[idx * 2 + 1];
//							}
//
//							mb->Vertices.push_back(vtx);
//						}
//
//						// compute normal
//						core::plane3d<f32> pl(mb->Vertices[vtxCount].Pos,
//								mb->Vertices[vtxCount + 2].Pos,
//								mb->Vertices[vtxCount + 1].Pos);
//
//						mb->Vertices[vtxCount].Normal = pl.Normal;
//						mb->Vertices[vtxCount + 1].Normal = pl.Normal;
//						mb->Vertices[vtxCount + 2].Normal = pl.Normal;
//
//						// add indices
//
//						mb->Indices.push_back(vtxCount);
//						mb->Indices.push_back(vtxCount + 2);
//						mb->Indices.push_back(vtxCount + 1);
//					}
//				}
//				else
//					os::Printer::log(
//							"Found no matching material for Group in 3ds file.",
//							ELL_WARNING);
//			}
//
//			cleanUp();
//		}
//
//		void C3DSMeshFileLoader::loadMaterials(io::IReadFile* file)
//		{
//			// create a mesh buffer for every material
//			core::stringc modelFilename = file->getFileName();
//
//			if (Materials.empty())
//				os::Printer::log("No materials found in 3ds file.",
//						ELL_INFORMATION);
//
//			MeshBufferNames.reallocate(Materials.size());
//			for (u32 i = 0; i < Materials.size(); ++i)
//			{
//				MeshBufferNames.push_back("");
//				SMeshBuffer* m = new scene::SMeshBuffer();
//				Mesh->addMeshBuffer(m);
//
//				m->getMaterial() = Materials[i].Material;
//				if (Materials[i].Filename[0].size())
//				{
//					video::ITexture* texture = 0;
//					if (FileSystem->existFile(Materials[i].Filename[0]))
//						texture = SceneManager->getVideoDriver()->getTexture(
//								Materials[i].Filename[0]);
//					if (!texture)
//					{
//						const core::stringc fname = FileSystem->getFileDir(
//								modelFilename) + "/"
//								+ FileSystem->getFileBasename(
//										Materials[i].Filename[0]);
//						if (FileSystem->existFile(fname))
//							texture =
//									SceneManager->getVideoDriver()->getTexture(
//											fname);
//					}
//					if (!texture)
//						os::Printer::log(
//								"Could not load a texture for entry in 3ds file",
//								Materials[i].Filename[0].c_str(), ELL_WARNING);
//					else
//						m->getMaterial().setTexture(0, texture);
//				}
//
//				if (Materials[i].Filename[2].size())
//				{
//					video::ITexture* texture = 0;
//					if (FileSystem->existFile(Materials[i].Filename[2]))
//						texture = SceneManager->getVideoDriver()->getTexture(
//								Materials[i].Filename[2]);
//					if (!texture)
//					{
//						const core::stringc fname = FileSystem->getFileDir(
//								modelFilename) + "/"
//								+ FileSystem->getFileBasename(
//										Materials[i].Filename[2]);
//						if (FileSystem->existFile(fname))
//							texture =
//									SceneManager->getVideoDriver()->getTexture(
//											fname);
//					}
//					if (!texture)
//					{
//						os::Printer::log(
//								"Could not load a texture for entry in 3ds file",
//								Materials[i].Filename[2].c_str(), ELL_WARNING);
//					}
//					else
//					{
//						m->getMaterial().setTexture(0, texture);
//						m->getMaterial().MaterialType =
//								video::EMT_TRANSPARENT_ADD_COLOR;
//					}
//				}
//
//				if (Materials[i].Filename[3].size())
//				{
//					video::ITexture* texture = 0;
//					if (FileSystem->existFile(Materials[i].Filename[3]))
//						texture = SceneManager->getVideoDriver()->getTexture(
//								Materials[i].Filename[3]);
//					if (!texture)
//					{
//						const core::stringc fname = FileSystem->getFileDir(
//								modelFilename) + "/"
//								+ FileSystem->getFileBasename(
//										Materials[i].Filename[3]);
//						if (FileSystem->existFile(fname))
//							texture =
//									SceneManager->getVideoDriver()->getTexture(
//											fname);
//					}
//
//					if (!texture)
//					{
//						os::Printer::log(
//								"Could not load a texture for entry in 3ds file",
//								Materials[i].Filename[3].c_str(), ELL_WARNING);
//					}
//					else
//					{
//						m->getMaterial().setTexture(1,
//								m->getMaterial().getTexture(0));
//						m->getMaterial().setTexture(0, texture);
//						m->getMaterial().MaterialType =
//								video::EMT_REFLECTION_2_LAYER;
//					}
//				}
//
//				if (Materials[i].Filename[4].size())
//				{
//					video::ITexture* texture = 0;
//					if (FileSystem->existFile(Materials[i].Filename[4]))
//						texture = SceneManager->getVideoDriver()->getTexture(
//								Materials[i].Filename[4]);
//					if (!texture)
//					{
//						const core::stringc fname = FileSystem->getFileDir(
//								modelFilename) + "/"
//								+ FileSystem->getFileBasename(
//										Materials[i].Filename[4]);
//						if (FileSystem->existFile(fname))
//							texture =
//									SceneManager->getVideoDriver()->getTexture(
//											fname);
//					}
//					if (!texture)
//						os::Printer::log(
//								"Could not load a texture for entry in 3ds file",
//								Materials[i].Filename[4].c_str(), ELL_WARNING);
//					else
//					{
//						m->getMaterial().setTexture(1, texture);
//						SceneManager->getVideoDriver()->makeNormalMapTexture(
//								texture, Materials[i].Strength[4] * 10.f);
//						m->getMaterial().MaterialType =
//								video::EMT_PARALLAX_MAP_SOLID;
//						m->getMaterial().MaterialTypeParam = .035f;
//					}
//				}
//
//				m->drop();
//			}
//		}
//
//////! Constructor
////		C3DSMeshFileLoader::C3DSMeshFileLoader(ISceneManager* smgr, io::IFileSystem* fs)
////		: SceneManager(smgr), FileSystem(fs), Vertices(0), Indices(0), SmoothingGroups(0), TCoords(0),
////		CountVertices(0), FacesCount(0), TCoordsCount(0), Mesh(0)
////		{
////
////#ifdef _DEBUG
////			setDebugName("C3DSMeshFileLoader");
////#endif
////
////			TransformationMatrix.makeIdentity();
////		}
////
////	//! destructor
////		C3DSMeshFileLoader::~C3DSMeshFileLoader()
////		{
////
////
////
////			if (Mesh)
////				Mesh->drop();
////		}
////
////
//////! creates/loads an animated mesh from the file.
//////! \return Pointer to the created mesh. Returns 0 if loading failed.
//////! If you no longer need the mesh, you should call IAnimatedMesh::drop().
//////! See IReferenceCounted::drop() for more information.
////		IAnimatedMesh* C3DSMeshFileLoader::createMesh(io::IReadFile* file)
////		{
////
////		}
////
////
////
//
////
//
////
////
////
////
////
////
////
////
////
////
//
////
////
////
////
////
////
////
////
////
////
//	}
///* namespace scene */
//} /* namespace irrgame */
