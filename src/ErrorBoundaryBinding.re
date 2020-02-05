[@bs.deriving jsConverter]
type error = {
  name: string,
  message: string,
  stack: option(string),
};

[@bs.module "reason-error-boundary"] [@react.component]
external make:
  (
    ~showFallbackComponent: option((Js.t('a), string) => bool)=?,
    ~onErrorFallbackComponent: option((Js.t('a), string) => React.element)=?,
    ~children: React.element
  ) =>
  React.element =
  "ErrorBoundary";
