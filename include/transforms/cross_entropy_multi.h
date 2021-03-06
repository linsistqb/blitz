#ifndef INCLUDE_TRANSFORMS_CROSS_ENTROPY_MULTI_H_
#define INCLUDE_TRANSFORMS_CROSS_ENTROPY_MULTI_H_

#include "transforms/cost.h"

namespace blitz {

template<template <typename> class TensorType, typename DType>
class CrossEntropyMulti : public Cost<TensorType, DType> {
 public:
  explicit CrossEntropyMulti(const DType scale = 1.0) : scale_(scale) {}
  ~CrossEntropyMulti() {}

  virtual DType Apply(const shared_ptr<TensorType<DType> > output,
    const shared_ptr<TensorType<DType> > target);

  virtual void Derivative(
    const shared_ptr<TensorType<DType> > output,
    const shared_ptr<TensorType<DType> > target,
    shared_ptr<TensorType<DType> > result);

 private:
  const DType scale_;

  DISABLE_COPY_AND_ASSIGN(CrossEntropyMulti);
};

}  // namespace blitz

#endif  // INCLUDE_TRANSFORMS_CROSS_ENTROPY_MULTI_H_
