#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "GLTFObject.h"
#include "CameraPlayer.h"
#include "AdvancedMath.hpp"
#include "RigidbodyComponent.hpp"
#include "CollisionComponent.hpp"

namespace Diligent
{

class Player : public GLTFObject
{
public:
    Player(const SampleInitInfo& InitInfo, BackgroundMode backGround, RefCntAutoPtr<IRenderPass>& RenderPass);

    Player(const SampleInitInfo& InitInfo, BackgroundMode backGround, RefCntAutoPtr<IRenderPass>& RenderPass, std::string name);

    void Initialize(float3 spawnPosition, Quaternion spawnRotation, ReactPhysic* _reactPhysic, float3 cameraSpring, float capsuleRadius, float capsuleHeight, float cameraRotationSpeed, float cameraMoveSpeed);

    void UpdatePlayer(double CurrTime, double ElapsedTime, InputController& Controller);

    void SetCameraPlayer(CameraPlayer* c) { m_Camera = c; }
    CameraPlayer* GetCameraPlayer() { return m_Camera; }
    Camera* GetCamera() { return m_Camera; } 

    void SetCameraSpring(float3 s) { _cameraSpring = s; }
    float3 GetCameraSpring() { return _cameraSpring; }

private:
    //Camera
    CameraPlayer* m_Camera;
    float3 _cameraSpring;
};

}

#endif