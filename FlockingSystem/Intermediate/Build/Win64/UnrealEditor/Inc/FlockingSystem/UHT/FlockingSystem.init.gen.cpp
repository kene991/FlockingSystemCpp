// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFlockingSystem_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_FlockingSystem;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_FlockingSystem()
	{
		if (!Z_Registration_Info_UPackage__Script_FlockingSystem.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/FlockingSystem",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xD89A6A95,
				0x667EB288,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_FlockingSystem.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_FlockingSystem.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_FlockingSystem(Z_Construct_UPackage__Script_FlockingSystem, TEXT("/Script/FlockingSystem"), Z_Registration_Info_UPackage__Script_FlockingSystem, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xD89A6A95, 0x667EB288));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
