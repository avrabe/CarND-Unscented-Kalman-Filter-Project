#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;
using namespace std;


Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
    VectorXd rmse(4);
    rmse << 0, 0, 0, 0;

    if (estimations.size() != ground_truth.size()
        || estimations.size() == 0) {
        cout << "Invalid estimation or ground_truth data" << endl;
        return rmse;
    }

    for (int i = 0; i < estimations.size(); ++i) {
        VectorXd e = estimations[i] - ground_truth[i];
        e = e.array() * e.array();
        rmse += e;
    }
    double f = 1.0 / estimations.size();
    rmse = f * rmse;
    rmse = rmse.array().sqrt();
    return rmse;
}
