#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
	const vector<VectorXd> &ground_truth) {
	
	// Calculate RMSE
	VectorXd rmse(4);
	rmse << 0, 0, 0, 0;

	// Safety check, estimation vector size should not be zero and estimation size should be the same as ground truth
	if (estimations.size() != ground_truth.size() || estimations.size() == 0) {
		cout << "Invalid estimation or ground truth data" << endl;
		return rmse;
	}

	// Sum the squared residuals
	for (unsigned int i = 0; i < estimations.size()); ++i) {
		VectorXd residual = estimations[i] - ground_truth[i];

		// Coefficient multiplication
		residual = residual.array() * residual.array();
		rmse += residual;
	}

	// Calculate the mean
	rmse = rmse / estimations.size();

	// Calculate the square root
	rmse = rmse.array().sqrt();

	return rmse;
}
