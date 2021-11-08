/* -*- c++ -*- */
/*
 * Copyright 2021 gr-peak_selection author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <gnuradio/io_signature.h>
#include "peak_selection_impl.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

namespace gr {
  namespace peak_selection {

    using input_type = gr_complex;
    using output_type = gr_complex;
    peak_selection::sptr
    peak_selection::make(int vec_len_)
    {
      return gnuradio::make_block_sptr<peak_selection_impl>(vec_len_);
    }


    /*
     * The private constructor
     */
    peak_selection_impl::peak_selection_impl(int vec_len_)
      : gr::block("peak_selection",
              gr::io_signature::make(1 /* min inputs */, 1 /* max inputs */, sizeof(input_type)),
              gr::io_signature::make(1 /* min outputs */, 1 /*max outputs */, sizeof(output_type)))
    {
      vec_len = vec_len_;
      max_inds = std::vector<float>(vec_len, 0);
      mags = std::vector<float>(vec_len, 0);
    }

    void
    peak_selection_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    { 
      ninput_items_required[0] = noutput_items * vec_len;
    }

    /*
     * Our virtual destructor.
     */
    peak_selection_impl::~peak_selection_impl()
    {
    }

    int
    peak_selection_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const input_type *in = reinterpret_cast<const input_type*>(input_items[0]);
      output_type *out = reinterpret_cast<output_type*>(output_items[0]);

      for (size_t i = 0; i < noutput_items; i++)
      {
        for (size_t j = 0; j < vec_len; j++)
        {
          mags[j] = in[i*vec_len + j].real() * in[i*vec_len + j].real() + in[i*vec_len + j].imag() * in[i*vec_len + j].imag();
          max_inds[j] = max_inds[j] * 0.99;
        }
        std::vector<float>::iterator result = std::max_element(mags.begin(), mags.end());
        int index = std::distance(mags.begin(), result);

        //std::cout << mags[index - 1] << " " << mags[index] << " " << mags[index+1] << " " << index << "\n";

        max_inds[index] += 0.1; 

        result = std::max_element(max_inds.begin(), max_inds.end());
        index = std::distance(max_inds.begin(), result);

        

        out[i] = in[i*vec_len + index];
        // std::cout << in[i*vec_len + index].real() << " " << in[i*vec_len + index].imag() << " " << std::abs(in[i*vec_len + index]) << "\n";
      }
      
      consume_each(vec_len*noutput_items);
      return noutput_items;
    }

  } /* namespace peak_selection */
} /* namespace gr */

