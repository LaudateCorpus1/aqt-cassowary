// Copyright: 2014, Ableton AG, Berlin, all rights reserved

#pragma once

#include <ableton/cassowary/Contextual.hpp>
#include <ableton/build_system/Warnings.hpp>

ABL_DISABLE_WARNINGS
#include <QtCore/QPointer>
#include <QtQuick/QQuickItem>
ABL_RESTORE_WARNINGS

namespace ableton {
namespace cassowary {

class SolverItemError : public std::runtime_error
{
  using std::runtime_error::runtime_error;
};

class SolverItem : public Contextual
{
  Q_OBJECT

public:
  SolverItem(QQuickItem* pParent = 0);

  Q_PROPERTY(ableton::cassowary::Contextual* solver
             MEMBER mSolver NOTIFY solverChanged)
  Q_SIGNAL void solverChanged(ableton::cassowary::Contextual* solver);

  std::shared_ptr<Context> context() override;

protected:
  void add();
  void remove();
  void update(Context::DeferredCallback cb);

  virtual void addIn(Context& impl) = 0;
  virtual void removeIn(Context& impl) = 0;

private:
  void updateContext();

  QPointer<Contextual> mSolver;
  QPointer<Contextual> mParent;
  QPointer<Contextual> mContextual;
  std::shared_ptr<Context> mContext;
};

} // namespace cassowary
} // namespace ableton
