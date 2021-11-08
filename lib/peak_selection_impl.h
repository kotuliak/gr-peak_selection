/* -*- c++ -*- */
/*
 * Copyright 2021 gr-peak_selection author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_PEAK_SELECTION_PEAK_SELECTION_IMPL_H
#define INCLUDED_PEAK_SELECTION_PEAK_SELECTION_IMPL_H

#include <peak_selection/peak_selection.h>

namespace gr {
  namespace peak_selection {

    class peak_selection_impl : public peak_selection
    {
     private:
      // Nothing to declare in this block.
      int vec_len;
      std::vector<float> max_inds;
      std::vector<float> mags;

     public:
      peak_selection_impl(int vec_len_);
      ~peak_selection_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      // Where all the action really happens
      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
           
    };

  } // namespace peak_selection
} // namespace gr

#endif /* INCLUDED_PEAK_SELECTION_PEAK_SELECTION_IMPL_H */

