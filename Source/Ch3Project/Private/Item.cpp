#include "Item.h"

AItem::AItem()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Sicka_EnvPack2/Sicka_Scifi_Interior2/Mesh/SM_Props1_CanisterLight.SM_Props1_CanisterLight"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Sicka_EnvPack2/Sicka_Scifi_Interior2/Materials/MI_Props1_Triangle.MI_Props1_Triangle"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 90.0f;

}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(-80.0f, 0.0f, 20.0f));
	SetActorRotation(FRotator(0.0f, 90.0f, 0.0f)); // Pitch, Yaw, Roll(y√‡, z√‡, x√‡)
	SetActorScale3D(FVector(1.0f));

}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}


}