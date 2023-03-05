#pragma once
#include "IPoseEstimator.h"

class OpenCVPoseEstimator : public IPostEstimator {

public: 
	void makeImageGrayscale();
};