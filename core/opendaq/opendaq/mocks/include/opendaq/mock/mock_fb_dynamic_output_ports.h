/*
 * Copyright 2022-2024 openDAQ d.o.o.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once
#include <opendaq/function_block_impl.h>

class MockFunctionBlockDynamicOutputPortImpl : public daq::FunctionBlock
{
public:
    explicit MockFunctionBlockDynamicOutputPortImpl(daq::FunctionBlockTypePtr type,
                                   daq::ContextPtr ctx,
                                   const daq::ComponentPtr& parent,
                                   const daq::StringPtr& localId,
                                   const daq::PropertyObjectPtr& config);

    void onPacketReceived(const daq::InputPortPtr& port) override;
    void onDisconnected(const daq::InputPortPtr& port) override;

    static daq::FunctionBlockTypePtr CreateType();
};

OPENDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    INTERNAL_FACTORY,
    MockFunctionBlockDynamicOutputPort, daq::IFunctionBlock,
    daq::IFunctionBlockType*, info,
    daq::IContext*, ctx,
    daq::IComponent*, parent,
    daq::IString*, localId,
    daq::IPropertyObject*, config)