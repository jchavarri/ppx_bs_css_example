let className =
  TypedGlamor.(
    [%style
      {typed|
        background-color: blue;
      |typed}
    ]
    |. css
    |. toString
  );

let component = ReasonReact.statelessComponent("Page");

let handleClick = (_event, _self) => Js.log("clicked!");

let make = (~message, _children) => {
  ...component,
  render: self =>
    <div className onClick=(self.handle(handleClick))>
      (ReasonReact.string(message))
    </div>,
};