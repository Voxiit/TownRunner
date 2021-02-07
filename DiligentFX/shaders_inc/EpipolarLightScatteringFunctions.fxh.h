"#ifndef _EPIPOLAR_LIGHT_SCATTERING_FUNCTIONS_FXH_\n"
"#define _EPIPOLAR_LIGHT_SCATTERING_FUNCTIONS_FXH_\n"
"\n"
"void GetSunLightExtinctionAndSkyLight(in float3               f3PosWS,\n"
"                                      in float3               f3EarthCentre,\n"
"                                      in float3               f3LightDirection,\n"
"                                      in AirScatteringAttribs MediaAttribs,\n"
"\n"
"                                      in Texture2D<float2>    tex2DOccludedNetDensityToAtmTop,\n"
"                                      in SamplerState         tex2DOccludedNetDensityToAtmTop_sampler,\n"
"                                      in Texture2D< float3 >  tex2DAmbientSkylight,\n"
"                                      in SamplerState         tex2DAmbientSkylight_sampler,\n"
"\n"
"                                      out float3              f3Extinction,\n"
"                                      out float3              f3AmbientSkyLight)\n"
"{\n"
"    float3 f3DirFromEarthCentre = f3PosWS - f3EarthCentre;\n"
"    float fDistToCentre = length(f3DirFromEarthCentre);\n"
"    f3DirFromEarthCentre /= fDistToCentre;\n"
"    float fAltitude = fDistToCentre - MediaAttribs.fEarthRadius;\n"
"    float fCosZenithAngle = dot(f3DirFromEarthCentre, -f3LightDirection);\n"
"\n"
"    float fNormalizedAltitude = (fAltitude - MediaAttribs.fAtmBottomAltitude) * MediaAttribs.fAtmAltitudeRangeInv;\n"
"    float2 f2ParticleDensityToAtmTop = tex2DOccludedNetDensityToAtmTop.SampleLevel( tex2DOccludedNetDensityToAtmTop_sampler, float2(fNormalizedAltitude, fCosZenithAngle*0.5 + 0.5), 0 );\n"
"    \n"
"    float3 f3RlghOpticalDepth = MediaAttribs.f4RayleighExtinctionCoeff.rgb * f2ParticleDensityToAtmTop.x;\n"
"    float3 f3MieOpticalDepth  = MediaAttribs.f4MieExtinctionCoeff.rgb      * f2ParticleDensityToAtmTop.y;\n"
"        \n"
"    f3Extinction = exp( -(f3RlghOpticalDepth + f3MieOpticalDepth) );\n"
"    \n"
"    f3AmbientSkyLight = tex2DAmbientSkylight.SampleLevel( tex2DAmbientSkylight_sampler, float2(fCosZenithAngle*0.5 + 0.5, 0.5), 0 );\n"
"}\n"
"\n"
"#endif //_EPIPOLAR_LIGHT_SCATTERING_FUNCTIONS_FXH_\n"
