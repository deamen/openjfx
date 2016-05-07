/*
 * Copyright (C) 2012 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "InjectedBundleTest.h"

#include "PlatformUtilities.h"
#include <WebKit2/WKBundlePage.h>

namespace TestWebKitAPI {

class WillSendSubmitEventTest : public InjectedBundleTest {
public:
    WillSendSubmitEventTest(const std::string& identifier);

    virtual void didCreatePage(WKBundleRef, WKBundlePageRef);
};

static InjectedBundleTest::Register<WillSendSubmitEventTest> registrar("WillSendSubmitEventTest");

static void willSendSubmitEvent(WKBundlePageRef, WKBundleNodeHandleRef, WKBundleFrameRef, WKBundleFrameRef, WKDictionaryRef values, const void*)
{
    WKBundlePostMessage(InjectedBundleController::shared().bundle(), Util::toWK("DidReceiveWillSendSubmitEvent").get(), values);
}

WillSendSubmitEventTest::WillSendSubmitEventTest(const std::string& identifier)
    : InjectedBundleTest(identifier)
{
}

void WillSendSubmitEventTest::didCreatePage(WKBundleRef bundle, WKBundlePageRef page)
{
    WKBundlePageFormClientV1 formClient;
    memset(&formClient, 0, sizeof(formClient));

    formClient.base.version = 1;
    formClient.base.clientInfo = this;
    formClient.willSendSubmitEvent = willSendSubmitEvent;

    WKBundlePageSetFormClient(page, &formClient.base);
}

} // namespace TestWebKitAPI