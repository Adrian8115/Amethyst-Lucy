// Automatically generated by FrederoxDev/Reverse-Tools/CxxParser/HeaderGenerator.py
#pragma once
#include <functional>
#include <optional>
#include <vector>
#include <thread>
 
#include <amethyst/Memory.hpp>
#include <minecraft/src-deps/core/headerIncludes/gsl_includes.hpp>
#include <minecraft/src-deps/core/utility/optional_ref.hpp>
#include <minecraft/src/common/world/level/BlockPos.hpp>
#include <minecraft/src/common/world/phys/AABB.hpp>
#include <minecraft/src/common/CommonTypes.hpp>
#include <minecraft/src/common/world/level/material/MaterialType.hpp>
#include <minecraft/src/common/world/level/block/GetCollisionShapeInterface.hpp>
#include <minecraft/src/common/world/phys/HitResult.hpp>
#include <minecraft/src/common/world/entity/EntityContext.hpp>
#include <minecraft/src/common/world/level/Level.hpp>
#include <minecraft/src/common/world/phys/ShapeType.hpp>
#include <minecraft/src-deps/core/utility/AutomaticID.hpp>
#include <minecraft/src/common/world/level/chunk/ChunkSource.hpp>

template <typename T>
class WeakRef {};

namespace BlockSourceVisitor { struct CollisionShape {}; }

enum ActorType {};

// Auto-generated: Forward declarations
class Block;
class BlockActor;
class Vec3;
class Material;
class LevelChunk;
struct Bounds;
class Actor;
class GameEvent;
class BlockSourceListener;
struct ActorBlockSyncMessage;
class ChunkPos;
class ItemStackBase; 
class Dimension;

#pragma pack(push, 8)
class BlockSource  {
public:
    std::byte padding8_enableSharedPadding[16]; // std::bit_cast not working with inheriting from std::enable_shared_from_this
    const std::thread::id mOwnerThreadID;
    const bool mAllowUnpopulatedChunks;
    const bool mPublicSource;
    bool mCheckValidity;
    Level* mLevel;
    ChunkSource* mChunkSource;
    Dimension* mDimension;
    const Height mMaxHeight;
    const Height mMinHeight;

public:
    virtual ~BlockSource();
    virtual const Block& getBlock(int x, int y, int z) const;
    virtual const Block& getBlock(const BlockPos& pos) const;
    virtual const Block& getBlock(const BlockPos& pos, unsigned int layer) const;
    virtual const BlockActor* getBlockEntity(const BlockPos& pos) const;
    virtual const Block& getExtraBlock(const BlockPos& p) const;
    virtual const Block& getLiquidBlock(const BlockPos& p) const;
    virtual bool hasBlock(const BlockPos& pos) const;
    virtual bool removeBlock(const BlockPos& pos);
    virtual bool containsAnyLiquid(const AABB& box) const;
    virtual bool containsMaterial(const AABB& box, MaterialType material) const;
    virtual bool isUnderWater(const Vec3& pos, const Block& block) const;
    virtual const Material& getMaterial(const BlockPos& pos) const;
    virtual const Material& getMaterial(int x, int y, int z) const;
    virtual bool hasBorderBlock(BlockPos pos) const;
    virtual LevelChunk* getChunkAt(const BlockPos& pos) const;
    virtual bool hasChunksAt(const Bounds& bounds, bool ignoreClientChunk) const;
    virtual bool hasChunksAt(const BlockPos& pos, int r, bool ignoreClientChunk) const;
    virtual bool hasChunksAt(const AABB& bb, bool ignoreClientChunk) const;
    virtual AutomaticID<Dimension, int> getDimensionId() const;
    virtual void fetchAABBs(std::vector<AABB>& shapes, const AABB& intersectTestBox, bool withUnloadedChunks) const;
    virtual void fetchCollisionShapes(std::vector<AABB>&, const AABB&, bool, optional_ref<const GetCollisionShapeInterface>, std::vector<AABB>*) const;
    virtual void fetchCollisionShapesAndBlocks(std::vector<BlockSourceVisitor::CollisionShape>&, const AABB&, bool, optional_ref<const GetCollisionShapeInterface>, std::vector<AABB>*) const;
    virtual AABB getTallestCollisionShape(const AABB& intersectTestBox, float* actualSurfaceOffset, bool withUnloadedChunks, optional_ref<const GetCollisionShapeInterface> entity) const;
    virtual float getBrightness(const BlockPos& pos) const;
    virtual void postGameEvent(Actor* source, const GameEvent& gameEvent, const BlockPos& originPos, const Block* affectedBlock);
    virtual std::vector<AABB>& fetchAABBs_(const AABB& intersectTestBox, bool withUnloadedChunks);
    virtual std::vector<AABB>& fetchCollisionShapes(const AABB&, bool, std::optional<const EntityContext>, std::vector<AABB>*);
    virtual WeakRef<BlockSource> getWeakRef();
    virtual void addListener(BlockSourceListener& l);
    virtual void removeListener(BlockSourceListener& l);
    virtual gsl::span<gsl::not_null<Actor*>> fetchEntities(const Actor* except, const AABB& bb, bool useHitbox, bool getDisplayEntities);
    virtual gsl::span<gsl::not_null<Actor*>> fetchEntities(ActorType, const AABB&, const Actor*, std::function<bool(Actor*)>);
    virtual bool setBlock(const BlockPos& pos, const Block& block, int updateFlags, const ActorBlockSyncMessage* syncMsg, Actor* blockChangeSource);
    virtual short getMinHeight() const;
    virtual short getMaxHeight() const;
    virtual Dimension& getDimension() const;
    virtual const Dimension& getDimensionConst() const;
    virtual void _unknown_38();
    virtual LevelChunk* getChunk(int x, int z) const;
    virtual LevelChunk* getChunk(const ChunkPos& pos) const;
    virtual void _unknown_41();
    virtual void _unknown_42();
    virtual HitResult clip(const Vec3&, const Vec3&, bool, ShapeType, int, bool, bool, Actor*, const std::function<bool(const BlockSource&, const Block&, bool)>&) const;
    virtual ChunkSource& getChunkSource();
    virtual bool isSolidBlockingBlock(const BlockPos& p) const;
    virtual bool isSolidBlockingBlock(int x, int y, int z) const;
    virtual bool areChunksFullyLoaded(const BlockPos& pos, int r) const;
    virtual bool canDoBlockDrops() const;
    virtual bool canDoContainedItemDrops() const;
    virtual bool isInstaticking(const BlockPos& pos) const;
    virtual void updateCheckForValidityState(bool checkForValidity);
    virtual bool checkBlockPermissions(Actor& entity, const BlockPos& blockPos, unsigned char face, const ItemStackBase& item, bool generateParticle);

public:
    // 1.20.71.1 - 48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B 01 49 8B D9
    // void postGameEvent(Actor* source, const GameEvent& gameEvent, const BlockPos& originPos, const Block* affectedBlock);
    // BlockActor* getBlockEntity(const BlockPos& pos);
};
#pragma pack(pop)