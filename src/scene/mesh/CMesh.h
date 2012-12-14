//// Copyright (C) 2002-2009 Nikolaus Gebhardt
//// This file is part of the "Irrlicht Engine".
//// For conditions of distribution and use, see copyright notice in irrlicht.h
//
//#ifndef CMESH_H_
//#define CMESH_H_
//
//#include "IMesh.h"
////#include "IMeshBuffer.h"
////#include "EHardwareMapping.h"
////#include "EBufferType.h"
////#include "core/shapes/aabbox3d.h"
////#include "core/collections/array.h"
////#include "video/material/EMaterialFlags.h"
//
//namespace irrgame
//{
//	namespace scene
//	{
//		//! Simple implementation of the IMesh interface.
//		class CMesh: public IMesh
//		{
//			public:
//				//! Default constructor
//				CMesh();
//
//				//! Destructor
//				virtual ~CMesh();
//
//				//! returns amount of mesh buffers.
//				virtual u32 getMeshBufferCount() const;
//
//				//! returns pointer to a mesh buffer
//				virtual IMeshBuffer* getMeshBuffer(u32 nr) const;
//
//				//! returns a meshbuffer which fits a material
//				/** reverse search */
//				virtual IMeshBuffer* getMeshBuffer(
//						const video::SMaterial & material) const;
//
//				//! returns an axis aligned bounding box
//				virtual const aabbox3df& getBoundingBox() const;
//
//				//! set user axis aligned bounding box
//				virtual void setBoundingBox(const aabbox3df& box);
//
//				//! recalculates the bounding box
//				void recalculateBoundingBox();
//
//				//! adds a MeshBuffer
//				virtual void addMeshBuffer(IMeshBuffer* buf);
//
//				//! sets a flag of all contained materials to a new value
//				virtual void setMaterialFlag(video::EMaterialFlag flag,
//						bool newvalue);
//
//				//! set the hardware mapping hint, for driver
//				virtual void setHardwareMappingHint(
//						EHardwareMapping newMappingHint, EBufferType buffer =
//								EBT_VERTEX_AND_INDEX);
//
//				//! flags the meshbuffer as changed, reloads hardware buffers
//				virtual void setDirty(
//						EBufferType buffer = EBT_VERTEX_AND_INDEX);
//
//			public:
//
//				//! The meshbuffers of this mesh
//				core::array<IMeshBuffer*> MeshBuffers;
//
//				//! The bounding box of this mesh
//				aabbox3df BoundingBox;
//		};
//
//	} // end namespace scene
//} // end namespace irrgame
//
//#endif /* CMESH_H_ */
//
