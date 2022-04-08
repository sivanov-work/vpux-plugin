//
// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache 2.0
//

// The file was generated by RecordedOpModel

#include <limits>
#include <include/mcm/op_model.hpp>
#include "include/mcm/compiler/compilation_unit.hpp"

int main()
{
    using namespace mv;

    static const auto inf = std::numeric_limits<double>::infinity();

    mv::CompilationUnit unit("Group_convolution");
    mv::OpModel& model = unit.model();
    std::string compDescPath = mv::utils::projectRootPath() + "/config/compilation/release_kmb.json";
    unit.loadCompilationDescriptor(compDescPath);
    unit.loadTargetDescriptor(mv::Target::ma2490);

    const auto data_0 = model.input("data", {27, 27, 96, 1}, mv::DType("UInt8"), mv::Order("NHWC"));
    data_0->setQuantParams({{0},{0.00196078431372549},{-inf},{inf},{0},{1}});

    std::vector<int64_t> weightsData0 = mv::utils::generateSequence<int64_t> (12288, 0, 0);
    auto weights0 = model.constantInt("", weightsData0, {1,1,48,256}, mv::DType("UInt8"), mv::Order("NCHW"));
    auto conv0 = model.conv("conv", data_0, weights0, {1, 1}, {0, 0, 0, 0}, 1, 2);
    weights0->setQuantParams({{0},{0.00392156862745098},{},{}});
    conv0->setQuantParams({{0},{0.00392156862745098},{-inf},{inf},{0},{1}});

    std::vector<int64_t> biasData0 = mv::utils::generateSequence<int64_t> (256, 0, 0);
    auto bias0 = model.constantInt("", biasData0, {256}, mv::DType("Int32"), mv::Order::getRowMajorID(1));
    auto bias = model.bias("", conv0, bias0);
    bias0->setQuantParams({{0}, {0.000000768935}, {}, {}});
    bias->setQuantParams({{0}, {0.000000768935}, {}, {}});

    model.output("", bias, mv::DType("Float16"));

    unit.initialize();
    unit.run();
}