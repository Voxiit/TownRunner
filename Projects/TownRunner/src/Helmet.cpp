#include "Helmet.h"
#include "Log.h"

namespace Diligent
{

Helmet::Helmet(const SampleInitInfo& InitInfo, BackgroundMode backGroundP, RefCntAutoPtr<IRenderPass>& RenderPass)
{
    GLTFObject::Initialize(InitInfo, RenderPass);
    setObjectPath("models/DamagedHelmet/DamagedHelmet.gltf");
    m_BackgroundMode = backGroundP;
}


Helmet::Helmet(const SampleInitInfo& InitInfo, BackgroundMode backGround, RefCntAutoPtr<IRenderPass>& RenderPass, std::string name)
{
    GLTFObject::Initialize(InitInfo, RenderPass);
    setObjectPath("models/DamagedHelmet/DamagedHelmet.gltf");
    m_BackgroundMode = backGround;
    _actorName       = name;
}


void Helmet::UpdateActor(double CurrTime, double ElapsedTime)
{
    GLTFObject::UpdateActor(CurrTime, ElapsedTime);

    //setPosition(float3(0.0f, cos(static_cast<float>(CurrTime) * 1.0f), sin(static_cast<float>(CurrTime) * 1.0f)));
    //setRotation(Quaternion::concatenate(getRotation(), Quaternion::RotationFromAxisAngle(float3(0, 1, 0), 0.01f)));

    //string message = "Hit point : " + std::to_string(position.x) + " - " + std::to_string(position.y) + " - " + std::to_string(position.z);
    //Diligent::Log::Instance().addInfo(message);
    //Diligent::Log::Instance().Draw();  
}

} // namespace Diligent