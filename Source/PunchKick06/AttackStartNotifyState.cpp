// Fill out your copyright notice in the Description page of Project Settings.

#include "AttackStartNotifyState.h"

#include "PunchKick06Character.h"

#include "Engine.h"

void UAttackStartNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	GEngine->AddOnScreenDebugMessage(-1, 4.5f, FColor::Magenta, __FUNCTION__);

	if (MeshComp != nullptr && MeshComp->GetOwner() != nullptr)
	{
		APunchKick06Character* Player = Cast<APunchKick06Character>(MeshComp->GetOwner());
		if (Player != nullptr)
		{
			Player->AttackStart();
		}
	}
}

void UAttackStartNotifyState::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	float FrameDeltaTime)
{
	if (MeshComp != nullptr && MeshComp->GetOwner() != nullptr)
	{
		APunchKick06Character* Player = Cast<APunchKick06Character>(MeshComp->GetOwner());
		if (Player != nullptr)
		{
			if(Player->GetCurrentAttackType()==EAttackType::MELEE_KICK)
			Player->SetIsKeyboardEnabled(false);
		}
	}
}

void UAttackStartNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	GEngine->AddOnScreenDebugMessage(-1, 4.5f, FColor::Magenta, __FUNCTION__);

	if (MeshComp != nullptr && MeshComp->GetOwner() != nullptr)
	{
		APunchKick06Character* Player = Cast<APunchKick06Character>(MeshComp->GetOwner());
		if (Player != nullptr)
		{
			Player->AttackEnd();
			Player->SetIsKeyboardEnabled(true);
		}
	}
}
