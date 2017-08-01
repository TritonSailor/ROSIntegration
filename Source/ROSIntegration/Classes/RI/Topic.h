// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <functional>
#include <memory>
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "ROSBaseMsg.h"
#include "Topic.generated.h"

UCLASS()
class ROSINTEGRATION_API UTopic: public UObject
{
	GENERATED_UCLASS_BODY()

public:
	void doSomething();

	void Subscribe(std::function<void(FROSBaseMsg&)> func);

	void Unsubscribe(std::function<void(FROSBaseMsg&)> func);

	void Advertise();
	
	void Unadvertise();
	
	void Publish(FROSBaseMsg& msg);

	void BeginDestroy() override;

private:
	// PIMPL
	class Impl;
	Impl* _Implementation;

	UPROPERTY()
	bool test;

};

