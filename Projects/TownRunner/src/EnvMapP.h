#pragma once
#include "Actor.h"
#include "GLTF_PBR_Renderer.hpp"
#include "Camera.h"
#include "EnvMap.h"

namespace Diligent
{

class EnvMap : public Actor
{
public:
    EnvMap();
    EnvMap(const SampleInitInfo& InitInfo, BackgroundMode BackgroundMode, RefCntAutoPtr<IRenderPass>& RenderPass);

    ~EnvMap();

    void Initialize(const SampleInitInfo& InitInfo) override;

    void RenderActor(const Camera& camera, bool IsShadowPass) override;

protected:
    const char* path;

    BackgroundMode m_BackgroundMode = BackgroundMode::EnvironmentMap;


private:
    void CreatePSO() override;
    void CreateVertexBuffer() override;

    GLTF_PBR_Renderer::RenderInfo m_RenderParams;
    RefCntAutoPtr<IRenderPass>    m_pRenderPass;

    float  m_EnvMapMipLevel = 1.f;
    int    m_SelectedModel  = 3;
};

} // namespace Diligent