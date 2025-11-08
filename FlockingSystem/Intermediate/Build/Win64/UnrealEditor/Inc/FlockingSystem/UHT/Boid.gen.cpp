// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlockingSystem/Boid.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoid() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	FLOCKINGSYSTEM_API UClass* Z_Construct_UClass_ABoid();
	FLOCKINGSYSTEM_API UClass* Z_Construct_UClass_ABoid_NoRegister();
	UPackage* Z_Construct_UPackage__Script_FlockingSystem();
// End Cross Module References
	void ABoid::StaticRegisterNativesABoid()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABoid);
	UClass* Z_Construct_UClass_ABoid_NoRegister()
	{
		return ABoid::StaticClass();
	}
	struct Z_Construct_UClass_ABoid_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Neighbor_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Neighbor_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Neighbor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Distance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CosAngleView_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CosAngleView;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TurnSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TurnSpeed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABoid_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_FlockingSystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABoid_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoid_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Boid.h" },
		{ "ModuleRelativePath", "Boid.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoid_Statics::NewProp_Neighbor_Inner = { "Neighbor", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ABoid_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoid_Statics::NewProp_Neighbor_MetaData[] = {
		{ "Category", "Boid" },
		{ "ModuleRelativePath", "Boid.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ABoid_Statics::NewProp_Neighbor = { "Neighbor", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoid, Neighbor), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoid_Statics::NewProp_Neighbor_MetaData), Z_Construct_UClass_ABoid_Statics::NewProp_Neighbor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoid_Statics::NewProp_Distance_MetaData[] = {
		{ "Category", "Boid" },
		{ "ModuleRelativePath", "Boid.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoid_Statics::NewProp_Distance = { "Distance", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoid, Distance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoid_Statics::NewProp_Distance_MetaData), Z_Construct_UClass_ABoid_Statics::NewProp_Distance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoid_Statics::NewProp_CosAngleView_MetaData[] = {
		{ "Category", "Boid" },
		{ "ModuleRelativePath", "Boid.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoid_Statics::NewProp_CosAngleView = { "CosAngleView", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoid, CosAngleView), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoid_Statics::NewProp_CosAngleView_MetaData), Z_Construct_UClass_ABoid_Statics::NewProp_CosAngleView_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoid_Statics::NewProp_Speed_MetaData[] = {
		{ "Category", "Boid" },
		{ "ModuleRelativePath", "Boid.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoid_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoid, Speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoid_Statics::NewProp_Speed_MetaData), Z_Construct_UClass_ABoid_Statics::NewProp_Speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoid_Statics::NewProp_TurnSpeed_MetaData[] = {
		{ "Category", "Boid" },
		{ "ModuleRelativePath", "Boid.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoid_Statics::NewProp_TurnSpeed = { "TurnSpeed", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoid, TurnSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoid_Statics::NewProp_TurnSpeed_MetaData), Z_Construct_UClass_ABoid_Statics::NewProp_TurnSpeed_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABoid_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoid_Statics::NewProp_Neighbor_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoid_Statics::NewProp_Neighbor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoid_Statics::NewProp_Distance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoid_Statics::NewProp_CosAngleView,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoid_Statics::NewProp_Speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoid_Statics::NewProp_TurnSpeed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABoid_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABoid>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABoid_Statics::ClassParams = {
		&ABoid::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ABoid_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ABoid_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoid_Statics::Class_MetaDataParams), Z_Construct_UClass_ABoid_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABoid_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ABoid()
	{
		if (!Z_Registration_Info_UClass_ABoid.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABoid.OuterSingleton, Z_Construct_UClass_ABoid_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ABoid.OuterSingleton;
	}
	template<> FLOCKINGSYSTEM_API UClass* StaticClass<ABoid>()
	{
		return ABoid::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABoid);
	ABoid::~ABoid() {}
	struct Z_CompiledInDeferFile_FID_FlockingSystem_Source_FlockingSystem_Boid_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FlockingSystem_Source_FlockingSystem_Boid_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABoid, ABoid::StaticClass, TEXT("ABoid"), &Z_Registration_Info_UClass_ABoid, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABoid), 638156241U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FlockingSystem_Source_FlockingSystem_Boid_h_3490940001(TEXT("/Script/FlockingSystem"),
		Z_CompiledInDeferFile_FID_FlockingSystem_Source_FlockingSystem_Boid_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FlockingSystem_Source_FlockingSystem_Boid_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
