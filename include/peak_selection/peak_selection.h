/* -*- c++ -*- */
/*
 * Copyright 2021 gr-peak_selection author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_PEAK_SELECTION_PEAK_SELECTION_H
#define INCLUDED_PEAK_SELECTION_PEAK_SELECTION_H

#include <peak_selection/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace peak_selection {

    /*!
     * \brief <+description of block+>
     * \ingroup peak_selection
     *
     */
    class PEAK_SELECTION_API peak_selection : virtual public gr::block
    {
     public:
      typedef std::shared_ptr<peak_selection> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of peak_selection::peak_selection.
       *
       * To avoid accidental use of raw pointers, peak_selection::peak_selection's
       * constructor is in a private implementation
       * class. peak_selection::peak_selection::make is the public interface for
       * creating new instances.
       */
      static sptr make(int vec_len_);
    };

  } // namespace peak_selection
} // namespace gr

#endif /* INCLUDED_PEAK_SELECTION_PEAK_SELECTION_H */

