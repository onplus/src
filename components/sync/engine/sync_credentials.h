// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_SYNC_ENGINE_SYNC_CREDENTIALS_H_
#define COMPONENTS_SYNC_ENGINE_SYNC_CREDENTIALS_H_

#include <string>

#include "google_apis/gaia/oauth2_token_service.h"

namespace syncer {

// Contains everything needed to talk to and identify a user account.
struct SyncCredentials {
  SyncCredentials();
  SyncCredentials(const SyncCredentials& other);
  ~SyncCredentials();

  // Account_id of signed in account.
  std::string account_id;

  // The email associated with this account.
  std::string email;

  // The raw authentication token's bytes.
  std::string sync_token;

  // The set of scopes to use when talking to sync server.
  OAuth2TokenService::ScopeSet scope_set;
};

}  // namespace syncer

#endif  // COMPONENTS_SYNC_ENGINE_SYNC_CREDENTIALS_H_
