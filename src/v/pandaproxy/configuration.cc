// Copyright 2020 Vectorized, Inc.
//
// Use of this software is governed by the Business Source License
// included in the file licenses/BSL.md
//
// As of the Change Date specified in that file, in accordance with
// the Business Source License, use of this software will be governed
// by the Apache License, Version 2.0

#include "configuration.h"

#include "config/configuration.h"
#include "units.h"

namespace pandaproxy {
using namespace std::chrono_literals;

configuration::configuration(const YAML::Node& cfg)
  : configuration() {
    read_yaml(cfg);
}

configuration::configuration()
  : pandaproxy_api(
    *this,
    "pandaproxy_api",
    "Rest API listen address and port",
    config::required::no,
    unresolved_address("127.0.0.1", 8082))
  , pandaproxy_api_tls(
      *this,
      "pandaproxy_api_tls",
      "TLS configuration for Pandaproxy api",
      config::required::no,
      config::tls_config(),
      config::tls_config::validate)
  , advertised_pandaproxy_api(
      *this,
      "advertised_pandaproxy_api",
      "Rest API address and port to publish to client",
      config::required::no,
      pandaproxy_api)
  , api_doc_dir(
      *this,
      "api_doc_dir",
      "API doc directory",
      config::required::no,
      "/usr/share/redpanda/proxy-api-doc") {}

} // namespace pandaproxy
