// Copyright 2024 The Mako Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <string>
#include <tuple>
#include <vector>

#include <torch/torch.h>

#include "mako/utils/export.h"

namespace mako {
namespace utils {
/// \brief Utility to download and initialize HuggingFace's Transformers model.
/// \param model_name_or_path A path to a directory containing model weights saved using ``save_pretrained``.
/// \param cache_dir Path to the folder where cached files are stored.
/// \param load_format Format of the model to load. Must be one of ``"auto"``, ``"safetensors"``, ``"pt"``, or ``"npcache"``.
/// \param revision An optional Git revision id which can be a branch name, a tag, or a commit hash.
/// \param fall_back_to_pt If ``true``, will always allow pt format.
/// \return Pairs of name and weight of the loaded model.
std::vector<std::tuple<std::string, torch::Tensor>> MAKO_API hf_model_weights(
    std::string model_name_or_path,
    std::string cache_dir   = "~/.cache/huggingface/hub",
    std::string load_format = "auto",
    std::string revision    = "main",
    bool fall_back_to_pt    = true);
} // namespace utils
} // namespace mako