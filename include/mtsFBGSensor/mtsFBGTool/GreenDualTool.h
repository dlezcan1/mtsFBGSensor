#pragma once

#include <cisstMultiTask.h>

#include "FBGToolInterface.h"

class CISST_EXPORT GreenDualTool : public FBGToolInterface
{
    CMN_DECLARE_SERVICES(CMN_NO_DYNAMIC_CREATION, CMN_LOG_LOD_RUN_VERBOSE);

public:

    // initialize with a json file
    GreenDualTool(const std::string& filename);
    virtual ~GreenDualTool();

    virtual mtsDoubleVec GetForcesTip(const mtsDoubleVec& wavelengths);
    virtual mtsDoubleVec GetForcesSclera(const mtsDoubleVec& wavelengths);
    virtual double GetForcesTipNorm(const mtsDoubleVec& forces) const override;

protected:
    mtsDouble m_DistanceScleraFBGs;
    
    // Calibration matrices
    mtsDoubleMat m_CalibrationMatrixTip;
    mtsDoubleMat m_CalibrationMatrixSclera2;
    mtsDoubleMat m_CalibrationMatrixSclera3;

    // Conversion matrices
    mtsDoubleMat m_WLConversionTipToSclera2;
    mtsDoubleMat m_WLConversionTipToSclera3;

    // wavelength indicators
    std::vector<size_t> m_IndicesTip;
    std::vector<size_t> m_IndicesSclera2;
    std::vector<size_t> m_IndicesSclera3;

}; // class: GreenDualTool

CMN_DECLARE_SERVICES_INSTANTIATION(GreenDualTool);