[@bs.val] external reload: unit => unit = "window.location.reload";

type error =
  | ChunkLoadError
  | Other;

let getErrorType = (error: string) => {
  switch (error) {
  | "ChunkLoadError" => ChunkLoadError
  | _ => Other
  };
};

let handleError = (error: Js.t('a)) => {
  let errorRecord = ErrorBoundaryComponent.errorFromJs(error);
  let errorType = getErrorType(errorRecord.name);
  switch (errorType) {
  | ChunkLoadError => false
  | _ => false
  };
};

[@react.component]
let make = (~children) => {
  <ErrorBoundaryComponent
    handleError={Some((error: Js.t('a), _stack: string) => handleError(error))}
    onErrorFallbackComponent={Some((_error: Js.t('a), _stack: string) =>
      <ErrorViewComponent reloadCB=reload />)
    }>
    children
  </ErrorBoundaryComponent>;
};
