/*
*	Terrain Mesh
*
*	Author: SiZhong.Wang, M-001
*
*	CopyRight: SilverEyes Information CO. LTD.
*/
#pragma once

#include "MNode.h"
#include "MTerrain.h"

namespace Rad {

#define TN_MAP(i, j, size) (((size) - (j) - 1) * (size)  + (i))

	class TerrainSection;

	class M_ENTRY TerrainMesh : public Node, public RenderObject
	{
		DECLARE_RTTI();

		friend class TerrainSection;

	public:
		TerrainMesh();
		~TerrainMesh();

		void
			Init(const Int2 & index);

		void 
			Build();
		void
			Destroy();
		bool
			IsValid();

		virtual void
			Serialize(Serializer & sl);

		virtual void
			Update(float elapsedTime);
		virtual void 
			AddRenderQueue(RenderQueue * rq);

		virtual void 
			_preRendering();
		virtual void
			_postRendering();

		int 
			GetLevel() const { return mLevel; }
		const Int2 &
			GetIndex() const { return mIndex; }
		
		void 
			SetLayer(int index, int layer) { mLayer[index] = layer; }
		int 
			GetLayer(int index) const { return mLayer[index]; }
		int 
			GetMaxLayer() const;

		TerrainSection *
			GetSection() { return mSection; }

		void
			SetUnused(bool unused);
		bool
			IsUnused() { return mUnused; }

		Float4
			GetXZTransform();

		float				
			GetHeight(int x, int z);
		Float3				
			GetNormal(int x, int z);
		Rgba32
			GetWeight(int x, int z);
		Rgba32
			GetLightingColor(int x, int z);

		void 
			_updateHeight(const RectI & rc);
		void
			_updateLayers();
		void
			_updateWeightMap(const RectI & rc, const Array<Rgba32> & data);
		void 
			_updateLightingMap(const Array<Rgba32> & lightingColor);
		void
			_resetLighting();
		

		//void
			//_serialize(Serializer & sl, int ver);

	protected:
		void 
			calcuMorphBuffer();
		void 
			_calcuMorphBuffer(int level);
		void 
			calcuErrorMetrics();
		float 
			_calcuErrorMetric(int level);
		void 
			calcuLevelDistance();

		void
			_getWMapName(String & name);
		void
			_getLMapName(String & name);

		bool
			_hasLightingmap() { return mLightingMap != RenderHelper::Instance()->GetDefaultLightingMap(); }
		
	protected:
		Int2 mIndex;
		bool mUnused;

		TerrainSection * mSection;
		TerrainMesh * mNeighbor[4];
		int mLevel;
		Field<int, Terrain::kMaxBlendLayers> mLayer;
		float mErrorMetric[Terrain::kMaxDetailLevel];
		float mLevelDistSq[Terrain::kMaxDetailLevel];
		VertexBufferPtr mMorphBuffer[Terrain::kMaxDetailLevel];
		Terrain::LodKey mLodKey;
		float mMorph;

		TexturePtr mWeightMap;
		TexturePtr mLightingMap;
		TexturePtr mDetailMaps[Terrain::kMaxDetailLevel];
		TexturePtr mNormalMaps[Terrain::kMaxDetailLevel];
	};

}