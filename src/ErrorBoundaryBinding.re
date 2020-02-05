[@bs.deriving jsConverter]
type error = {
  name: string,
  message: string,
  stack: option(string),
};

[@bs.module "reason-error-boundary"] [@react.component]
external make:
  (
    ~onError: option((Js.t('a), string) => unit)=?,
    ~fallbackComponent: option((Js.t('a), string) => React.element)=?,
    ~children: React.element
  ) =>
  React.element =
  "ErrorBoundary";
