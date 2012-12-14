///*
// * CMesh.cpp
// *
// *  Created on: Dec 12, 2012
// *      Author: gregorytkach
// */
//#include "CMesh.h"
//
//namespace irrgame
//{
//	namespace scene
//	{
//		//! Default constructor
//		CMesh::CMesh()
//		{
//#ifdef DEBUG
//			setDebugName("CMesh");
//#endif
//		}
//
//		//! Destructor
//		CMesh::~CMesh()
//		{
//			// drop buffers
//			for (u32 i = 0; i < MeshBuffers.size(); ++i)
//			{
//				MeshBuffers[i]->drop();
//			}
//		}
//
//		//! returns amount of mesh buffers.
//		u32 CMesh::getMeshBufferCount() const
//		{
//			return MeshBuffers.size();
//		}
//
//		//! returns pointer to a mesh buffer
//		IMeshBuffer* CMesh::getMeshBuffer(u32 nr) const
//		{
//			return MeshBuffers[nr];
//		}
//
//		//! returns a meshbuffer which fits a material
//		IMeshBuffer* CMesh::getMeshBuffer(
//				const video::SMaterial & material) const
//		{
//			IMeshBuffer* result = 0;
//
//			for (s32 i = (s32) MeshBuffers.size() - 1; i >= 0; --i)
//			{
//				if (material == MeshBuffers[i]->getMaterial())
//				{
//					result = MeshBuffers[i];
//					break;
//				}
//			}
//
//			return result;
//		}
//
//		//! returns an axis aligned bounding box
//		const aabbox3df& CMesh::getBoundingBox() const
//		{
//			return BoundingBox;
//		}
//
//		//! set user axis aligned bounding box
//		void CMesh::setBoundingBox(const aabbox3df& box)
//		{
//			BoundingBox = box;
//		}
//
//		//! recalculates the bounding box
//		void CMesh::recalculateBoundingBox()
//		{
//			if (MeshBuffers.size())
//			{
//				BoundingBox = MeshBuffers[0]->getBoundingBox();
//				for (u32 i = 1; i < MeshBuffers.size(); ++i)
//				{
//					BoundingBox.addInternalBox(
//							MeshBuffers[i]->getBoundingBox());
//				}
//			}
//			else
//			{
//				BoundingBox.reset(0.0f, 0.0f, 0.0f);
//			}
//		}
//
//		//! adds a MeshBuffer
//		void CMesh::addMeshBuffer(IMeshBuffer* value)
//		{
//			IRR_ASSERT(value);
//
//			value->grab();
//			MeshBuffers.pushBack(value);
//		}
//
//		//! sets a flag of all contained materials to a new value
//		void CMesh::setMaterialFlag(video::EMaterialFlag flag, bool newvalue)
//		{
//			for (u32 i = 0; i < MeshBuffers.size(); ++i)
//			{
//				MeshBuffers[i]->getMaterial().setFlag(flag, newvalue);
//			}
//		}
//
//		//! set the hardware mapping hint, for driver
//		void CMesh::setHardwareMappingHint(EHardwareMapping newMappingHint,
//				EBufferType buffer)
//		{
//			for (u32 i = 0; i < MeshBuffers.size(); ++i)
//			{
//				MeshBuffers[i]->setHardwareMappingHint(newMappingHint, buffer);
//			}
//		}
//
//		//! flags the meshbuffer as changed, reloads hardware buffers
//		void CMesh::setDirty(EBufferType buffer)
//		{
//			for (u32 i = 0; i < MeshBuffers.size(); ++i)
//			{
//				MeshBuffers[i]->setDirty(buffer);
//			}
//		}
//
//	}  // namespace scene
//}  // namespace irrgame
//
