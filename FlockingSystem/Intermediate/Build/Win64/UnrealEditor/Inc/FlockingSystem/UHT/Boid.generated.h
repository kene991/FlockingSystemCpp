// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Boid.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FLOCKINGSYSTEM_Boid_generated_h
#error "Boid.generated.h already included, missing '#pragma once' in Boid.h"
#endif
#define FLOCKINGSYSTEM_Boid_generated_h

#define FID_FlockingSystem_Source_FlockingSystem_Boid_h_13_SPARSE_DATA
#define FID_FlockingSystem_Source_FlockingSystem_Boid_h_13_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_FlockingSystem_Source_FlockingSystem_Boid_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_FlockingSystem_Source_FlockingSystem_Boid_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_FlockingSystem_Source_FlockingSystem_Boid_h_13_ACCESSORS
#define FID_FlockingSystem_Source_FlockingSystem_Boid_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABoid(); \
	friend struct Z_Construct_UClass_ABoid_Statics; \
public: \
	DECLARE_CLASS(ABoid, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FlockingSystem"), NO_API) \
	DECLARE_SERIALIZER(ABoid)


#define FID_FlockingSystem_Source_FlockingSystem_Boid_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABoid(ABoid&&); \
	NO_API ABoid(const ABoid&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoid); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoid); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABoid) \
	NO_API virtual ~ABoid();


#define FID_FlockingSystem_Source_FlockingSystem_Boid_h_10_PROLOG
#define FID_FlockingSystem_Source_FlockingSystem_Boid_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_FlockingSystem_Source_FlockingSystem_Boid_h_13_SPARSE_DATA \
	FID_FlockingSystem_Source_FlockingSystem_Boid_h_13_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_FlockingSystem_Source_FlockingSystem_Boid_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_FlockingSystem_Source_FlockingSystem_Boid_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_FlockingSystem_Source_FlockingSystem_Boid_h_13_ACCESSORS \
	FID_FlockingSystem_Source_FlockingSystem_Boid_h_13_INCLASS_NO_PURE_DECLS \
	FID_FlockingSystem_Source_FlockingSystem_Boid_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FLOCKINGSYSTEM_API UClass* StaticClass<class ABoid>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_FlockingSystem_Source_FlockingSystem_Boid_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
