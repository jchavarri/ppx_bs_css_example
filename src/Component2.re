type state = {
  count: int,
  show: bool,
};

type action =
  | Click
  | Toggle;

let className =
  TypedGlamor.(
    [%css
      {typed|
        {
          background-color: red;
        }
        :hover {
          background-color: black;
        }
      |typed}
    ]
    |. css
    |. toString
  );

let component = ReasonReact.reducerComponent("Example");

let make = (~greeting, _children) => {
  /* spread the other default fields of component here and override a few */
  ...component,

  initialState: () => {count: 0, show: true},

  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | Click => ReasonReact.Update({...state, count: state.count + 1})
    | Toggle => ReasonReact.Update({...state, show: ! state.show})
    },

  render: self => {
    let message =
      "You've clicked this " ++ string_of_int(self.state.count) ++ " times(s)";
    <div className>
      <button onClick=(_event => self.send(Click))>
        (ReasonReact.string(message))
      </button>
      <button onClick=(_event => self.send(Toggle))>
        (ReasonReact.string("Toggle greeting"))
      </button>
      (self.state.show ? ReasonReact.string(greeting) : ReasonReact.null)
    </div>;
  },
};
