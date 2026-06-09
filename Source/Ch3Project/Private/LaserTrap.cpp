#include "LaserTrap.h"

ALaserTrap::ALaserTrap()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Sicka_EnvPack2/Sicka_Scifi_Interior2/Mesh/SM_Cables_ThinSolo.SM_Cables_ThinSolo"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Sicka_EnvPack2/Sicka_Scifi_Interior2/Materials/M_MonitorScreen.M_MonitorScreen"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

}

void ALaserTrap::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

}

void ALaserTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();

	if (bMovingUp)
	{
		CurrentLocation.Z += MoveSpeed * DeltaTime;

		if (CurrentLocation.Z >= StartLocation.Z + MaxRange)
		{
			CurrentLocation.Z = StartLocation.Z + MaxRange;
			bMovingUp = false;
		}
	}
	else
	{
		CurrentLocation.Z -= MoveSpeed * DeltaTime;

		if (CurrentLocation.Z <= StartLocation.Z - MaxRange)
		{
			CurrentLocation.Z = StartLocation.Z - MaxRange;
			bMovingUp = true;
		}
	}

	SetActorLocation(CurrentLocation);
}

