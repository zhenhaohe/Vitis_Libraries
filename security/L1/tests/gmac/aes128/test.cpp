/*
 * Copyright 2019 Xilinx, Inc.
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

#include "test.hpp"
#include "xf_security/gmac.hpp"

void aes128GmacTop(hls::stream<ap_uint<128> >& dataStrm,
          hls::stream<ap_uint<64> >& lenDataStrm,
          hls::stream<ap_uint<128> >& cipherkeyStrm,
          hls::stream<ap_uint<96> >& IVStrm,
          hls::stream<ap_uint<128> >& tagStrm) {
#if defined(__SYNTHESIS__)
#pragma HLS INTERFACE axis register  port=dataStrm
#pragma HLS INTERFACE axis register  port=lenDataStrm
#pragma HLS INTERFACE axis register  port=cipherkeyStrm
#pragma HLS INTERFACE axis register  port=IVStrm
#pragma HLS INTERFACE axis register  port=tagStrm
#pragma HLS INTERFACE ap_ctrl_none port=return
#endif

    xf::security::aes128Gmac(dataStrm, lenDataStrm, cipherkeyStrm, IVStrm, tagStrm);
}
