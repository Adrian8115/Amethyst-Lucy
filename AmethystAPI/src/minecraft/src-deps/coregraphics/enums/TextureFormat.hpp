#pragma once

namespace mce {
    enum class TextureFormat : unsigned int {
        UNKNOWN_TEXTURE_FORMAT, 
        R32G32B32A32_FLOAT = 2, 
        R16G16B16A16_FLOAT = 10, 
        R16G16B16A16_UNORM, 
        R32G32_FLOAT = 16, 
        R10G10B10A2_UNORM = 24, 
        R11G11B10_FLOAT = 26, 
        R8G8B8A8_UNORM = 28, 
        R8G8B8A8_UNORM_SRGB, 
        R16G16_FLOAT = 34, 
        R16G16_UNORM, 
        R16G16_UINT, 
        R16G16_SNORM, 
        D32_FLOAT = 40, 
        R32_FLOAT, 
        R32_UINT, 
        R24G8_TYPELESS = 44, 
        D24_UNORM_S8_UINT, 
        R24_UNORM_X8_TYPELESS, 
        R8G8_UNORM = 49, 
        R8G8_SNORM = 51, 
        R16_FLOAT = 54, 
        D16_UNORM, 
        R8_UNORM = 61, 
        R8_UINT, 
        A8_UNORM = 65, 
        BC3_UNORM = 77, 
        R5G6B5_UNORM = 85, 
        R5G5B5A1_UNORM, 
        B8G8R8A8_UNORM, 
        B8G8R8A8_UNORM_SRGB = 91, 
        BC7_UNORM = 98, 
        R4G4B4A4_UNORM = 115, 
        S8_UINT, 
        R8G8B8_UNORM
    };
}