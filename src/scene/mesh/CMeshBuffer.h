// Copyright (C) 2002-2009 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef CMESHBUFFER_H_
#define CMESHBUFFER_H_

#include "core/collections/array.h"
#include "video/vertex.h"
#include "IMeshBuffer.h"

namespace irrgame
{
	namespace scene
	{
		//! Template implementation of the IMeshBuffer interface
		template<class T>
		class CMeshBuffer: public IMeshBuffer
		{
			public:

				//! Default constructor for empty meshbuffer
				CMeshBuffer();

				//! Destructor
				virtual ~CMeshBuffer();

				//! Get material of this meshbuffer
				virtual const video::SMaterial& getMaterial() const;

				//! Get material of this meshbuffer
				/** \return Material of this buffer */
				virtual video::SMaterial& getMaterial();

				//! Get pointer to vertices
				/** \return Pointer to vertices. */
				virtual const void* getVertices() const;

				//! Get pointer to vertices
				/** \return Pointer to vertices. */
				virtual void* getVertices();

				//! Get number of vertices
				/** @return Number of vertices. */
				virtual u32 getVertexCount() const;

				//! Get type of index data which is stored in this meshbuffer.
				/** \return Index type of this buffer. */
				virtual video::E_INDEX_TYPE getIndexType() const;

				//! Get pointer to indices
				/** \return Pointer to indices. */
				virtual const u16* getIndices() const;

				//! Get pointer to indices
				/** \return Pointer to indices. */
				virtual u16* getIndices();

				//! Get number of indices
				/** \return Number of indices. */
				virtual u32 getIndexCount() const;

				//! Get the axis aligned bounding box
				/** \return Axis aligned bounding box of this buffer. */
				virtual const aabbox3df& getBoundingBox() const;

				//! Set the axis aligned bounding box
				/** \param box New axis aligned bounding box for this buffer. */
				//! set user axis aligned bounding box
				virtual void setBoundingBox(const aabbox3df& box);

				//! Recalculate the bounding box.
				/** should be called if the mesh changed. */
				virtual void recalculateBoundingBox();

				//! Get type of vertex data stored in this buffer.
				/** \return Type of vertex data. */
				virtual video::EVertexType getVertexType() const;

				//! returns position of vertex i
				virtual const vector3df& getPosition(u32 i) const;

				//! returns position of vertex i
				virtual vector3df& getPosition(u32 i);

				//! returns normal of vertex i
				virtual const vector3df& getNormal(u32 i) const

				//! returns normal of vertex i
				virtual vector3df& getNormal(u32 i)

				//! returns texture coord of vertex i
				virtual const vector2df& getTCoords(u32 i) const;

				//! returns texture coord of vertex i
				virtual vector2df& getTCoords(u32 i);

				//! Append the vertices and indices to the current buffer
				/** Only works for compatible types, i.e. either the same type
				 or the main buffer is of standard type. Otherwise, behavior is
				 undefined.
				 */
				virtual void append(const void* const vertices, u32 numVertices,
						const u16* const indices, u32 numIndices);

				//! Append the meshbuffer to the current buffer
				/** Only works for compatible types, i.e. either the same type
				 or the main buffer is of standard type. Otherwise, behavior is
				 undefined.
				 \param other Meshbuffer to be appended to this one.
				 */
				virtual void append(const IMeshBuffer* const other);

				//! get the current hardware mapping hint
				virtual EHardwareMapping getHardwareMappingHint_Vertex() const;

				//! get the current hardware mapping hint
				virtual EHardwareMapping getHardwareMappingHint_Index() const;

				//! set the hardware mapping hint, for driver
				virtual void setHardwareMappingHint(
						EHardwareMapping NewMappingHint, EBufferType Buffer =
								EBT_VERTEX_AND_INDEX);

				//! flags the mesh as changed, reloads hardware buffers
				virtual void setDirty(EBufferType Buffer =
						EBT_VERTEX_AND_INDEX);

				//! Get the currently used ID for identification of changes.
				/** This shouldn't be used for anything outside the VideoDriver. */
				virtual u32 getChangedID_Vertex() const;

				//! Get the currently used ID for identification of changes.
				/** This shouldn't be used for anything outside the VideoDriver. */
				virtual u32 getChangedID_Index() const;

			private:

				u32 ChangedID_Vertex;
				u32 ChangedID_Index;

				//! hardware mapping hint
				EHardwareMapping MappingHint_Vertex;
				EHardwareMapping MappingHint_Index;

				//! Material for this meshbuffer.
				video::SMaterial Material;
				//! Vertices of this buffer
				core::array<T> Vertices;
				//! Indices into the vertices of this buffer.
				core::array<u16> Indices;
				//! Bounding box of this meshbuffer.
				aabbox3df BoundingBox;
		};

		//! Default constructor for empty meshbuffer
		template<class T>
		CMeshBuffer<T>::CMeshBuffer() :
				ChangedID_Vertex(1), ChangedID_Index(1), MappingHint_Vertex(
						EHM_NEVER), MappingHint_Index(EHM_NEVER)
		{
#ifdef DEBUG
			setDebugName("CMeshBuffer");
#endif
		}

		//! Destructor
		template<class T>
		CMeshBuffer<T>::~CMeshBuffer()
		{
		}

		//! Get material of this meshbuffer
		template<class T>
		const video::SMaterial& CMeshBuffer<T>::getMaterial() const
		{
			return Material;
		}

		//! Get material of this meshbuffer
		template<class T>
		virtual video::SMaterial& CMeshBuffer<T>::getMaterial()
		{
			return Material;
		}

		//! Get pointer to vertices
		template<class T>
		const void* CMeshBuffer<T>::getVertices() const
		{
			return Vertices.constPointer();
		}

		//! Get pointer to vertices
		template<class T>
		void* CMeshBuffer<T>::getVertices()
		{
			return Vertices.pointer();
		}

		//! Get number of vertices
		template<class T>
		virtual u32 CMeshBuffer<T>::getVertexCount() const
		{
			return Vertices.size();
		}

		//! Get type of index data which is stored in this meshbuffer.
		template<class T>
		video::EIndexType CMeshBuffer<T>::getIndexType() const
		{
			return video::EIT_16BIT;
		}

		//! Get pointer to indices
		template<class T>
		const u16* CMeshBuffer<T>::getIndices() const
		{
			return Indices.constPointer();
		}

		//! Get pointer to indices
		template<class T>
		u16* CMeshBuffer<T>::getIndices()
		{
			return Indices.pointer();
		}

		//! Get number of indices
		template<class T>
		u32 CMeshBuffer<T>::getIndexCount() const
		{
			return Indices.size();
		}

		//! Get the axis aligned bounding box
		template<class T>
		const aabbox3df& CMeshBuffer<T>::getBoundingBox() const
		{
			return BoundingBox;
		}

		//! Set the axis aligned bounding box
		template<class T>
		void CMeshBuffer<T>::setBoundingBox(const aabbox3df& box)
		{
			BoundingBox = box;
		}

		//! Recalculate the bounding box.
		template<class T>
		void CMeshBuffer<T>::recalculateBoundingBox()
		{
			if (Vertices.empty())
				BoundingBox.reset(0, 0, 0);
			else
			{
				BoundingBox.reset(Vertices[0].Pos);
				for (u32 i = 1; i < Vertices.size(); ++i)
				{
					BoundingBox.addInternalPoint(Vertices[i].Pos);
				}
			}
		}

		//! Get type of vertex data stored in this buffer.
		template<class T>
		video::EVertexType CMeshBuffer<T>::getVertexType() const
		{
			return T().getType();
		}

		//! returns position of vertex i
		template<class T>
		const vector3df& CMeshBuffer<T>::getPosition(u32 i) const
		{
			return Vertices[i].Pos;
		}

		//! returns position of vertex i
		template<class T>
		vector3df& CMeshBuffer<T>::getPosition(u32 i)
		{
			return Vertices[i].Pos;
		}

		//! returns normal of vertex i
		template<class T>
		const vector3df& CMeshBuffer<T>::getNormal(u32 i) const
		{
			return Vertices[i].Normal;
		}

		//! returns normal of vertex i
		template<class T>
		virtual vector3df& CMeshBuffer<T>::getNormal(u32 i)
		{
			return Vertices[i].Normal;
		}

		//! returns texture coord of vertex i
		template<class T>
		const vector2df& CMeshBuffer<T>::getTCoords(u32 i) const
		{
			return Vertices[i].TCoords;
		}

		//! returns texture coord of vertex i
		template<class T>
		vector2df& CMeshBuffer<T>::getTCoords(u32 i)
		{
			return Vertices[i].TCoords;
		}

		//! Append the vertices and indices to the current buffer
		template<class T>
		void CMeshBuffer<T>::append(const void* const vertices, u32 numVertices,
				const u16* const indices, u32 numIndices)
		{
			if (vertices == getVertices())
				return;

			const u32 vertexCount = getVertexCount();
			u32 i;

			Vertices.reallocate(vertexCount + numVertices);
			for (i = 0; i < numVertices; ++i)
			{
				Vertices.push_back(reinterpret_cast<const T*>(vertices)[i]);
				BoundingBox.addInternalPoint(
						reinterpret_cast<const T*>(vertices)[i].Pos);
			}

			Indices.reallocate(getIndexCount() + numIndices);
			for (i = 0; i < numIndices; ++i)
			{
				Indices.pushBack(indices[i] + vertexCount);
			}
		}

		//! Append the meshbuffer to the current buffer
		template<class T>
		void CMeshBuffer<T>::append(const IMeshBuffer* const other)
		{
			if (this == other)
				return;

			const u32 vertexCount = getVertexCount();
			u32 i;

			Vertices.reallocate(vertexCount + other->getVertexCount());
			for (i = 0; i < other->getVertexCount(); ++i)
			{
				Vertices.push_back(
						reinterpret_cast<const T*>(other->getVertices())[i]);
			}

			Indices.reallocate(getIndexCount() + other->getIndexCount());
			for (i = 0; i < other->getIndexCount(); ++i)
			{
				Indices.pushBack(other->getIndices()[i] + vertexCount);
			}

			BoundingBox.addInternalBox(other->getBoundingBox());

		}

		//! get the current hardware mapping hint
		template<class T>
		EHardwareMapping CMeshBuffer<T>::getHardwareMappingHint_Vertex() const
		{
			return MappingHint_Vertex;
		}

		//! get the current hardware mapping hint
		template<class T>
		EHardwareMapping CMeshBuffer<T>::getHardwareMappingHint_Index() const
		{
			return MappingHint_Index;
		}

		//! set the hardware mapping hint, for driver
		template<class T>
		void CMeshBuffer<T>::setHardwareMappingHint(
				EHardwareMapping NewMappingHint, EBufferType Buffer =
						EBT_VERTEX_AND_INDEX)
		{
			if (Buffer == EBT_VERTEX_AND_INDEX || Buffer == EBT_VERTEX)
			{
				MappingHint_Vertex = NewMappingHint;
			}
			if (Buffer == EBT_VERTEX_AND_INDEX || Buffer == EBT_INDEX)
			{
				MappingHint_Index = NewMappingHint;
			}
		}

		//! flags the mesh as changed, reloads hardware buffers
		template<class T>
		void CMeshBuffer<T>::setDirty(EBufferType Buffer =
				EBT_VERTEX_AND_INDEX)
		{
			if (Buffer == EBT_VERTEX_AND_INDEX || Buffer == EBT_VERTEX)
			{
				++ChangedID_Vertex;
			}
			if (Buffer == EBT_VERTEX_AND_INDEX || Buffer == EBT_INDEX)
			{
				++ChangedID_Index;
			}
		}

		//! Get the currently used ID for identification of changes.
		template<class T>
		virtual u32 CMeshBuffer<T>::getChangedID_Vertex() const
		{
			return ChangedID_Vertex;
		}

		//! Get the currently used ID for identification of changes.
		template<class T>
		virtual u32 CMeshBuffer<T>::getChangedID_Index() const
		{
			return ChangedID_Index;
		}

		//! Internal function. Please do not use.
		IMeshBuffer* createMeshBuffer()
		{
			return new CMeshBuffer<video::vertex3d>();
		}

		//! Internal function. Please do not use.
		IMeshBuffer* createMeshBufferLightMap()
		{
			return new CMeshBuffer<video::vertex3d2TCoords> ;
		}

		//! Internal function. Please do not use.
		IMeshBuffer* createMeshBufferTangents()
		{
			return CMeshBuffer<video::vertex3dTangents> ;
		}

	} // end namespace scene
} // end namespace irrgame

#endif /* CMESHBUFFER_H_ */

