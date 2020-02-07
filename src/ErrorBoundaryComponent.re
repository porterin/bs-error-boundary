[@bs.deriving jsConverter]
type error = {
  name: string,
  message: string,
  stack: option(string),
};

[@bs.module "react-error-boundary-ts"] [@react.component]
external make:
  (
    ~handleError: option((Js.t('a), string) => bool)=?,
    ~onErrorFallbackComponent: option((Js.t('a), string) => React.element)=?,
    ~children: React.element
  ) =>
  React.element =
  "ErrorBoundary";
