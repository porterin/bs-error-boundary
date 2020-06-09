[@react.component]
let make = (~reloadCB: unit => unit) => {
  <div
    style={ReactDOMRe.Style.make(
      ~fontFamily="Lato",
      ~display="flex",
      ~flexDirection="column",
      ~alignItems="center",
      ~marginTop="15%",
      (),
    )}>
    <div style={ReactDOMRe.Style.make(~fontSize=".9rem", ())}>
      {React.string("Something went wrong!")}
    </div>
    <a
      style={ReactDOMRe.Style.make(
        ~color="blue",
        ~marginTop=".5em",
        ~cursor="pointer",
        ~fontSize=".9rem",
        (),
      )}
      onClick={_ => reloadCB()}>
      {React.string("Try reloading the page")}
    </a>
  </div>;
};
